#include "DynaPacket_m.h"
#include "quic/model/packets/InitialPacket.h"
#include "quic/model/frames/CryptoFrame.h"
#include "quic/model/frames/PingFrame.h"
#include "quic/model/frames/AckFrame.h"
#include "quic/model/frames/HandshakeDoneFrame.h"
#include "quic/model/packets/PacketType.h"
#include "quic/model/packets/ShortHeaderOneRttPacket.h"
#include "quic/model/packets/HandshakePacket.h"
using namespace omnetpp;

#define STACKSIZE    16384

/**
 * Client computer; see NED file for more info
 */
class Client : public cSimpleModule
{
  public:
    Client() : cSimpleModule(STACKSIZE) {}
    virtual void activity() override;
};

Define_Module(Client);

void Client::activity()
{
    // query module parameters
    simtime_t timeout = par("timeout");
    cPar& connectionIaTime = par("connIaTime");
    cPar& queryIaTime = par("queryIaTime");
    cPar& numQuery = par("numQuery");

    QuicPacket *connReq, *connAck, *discReq, *discAck;
    QuicPacket *query, *answer;
    int actNumQuery = 0, i = 0;
    WATCH(actNumQuery);
    WATCH(i);

    // assign address: index of Switch's gate to which we are connected
    int ownAddr = gate("port$o")->getNextGate()->getIndex();
    int serverAddr = gate("port$o")->getNextGate()->size()-1;
    int serverprocId = 0;
    WATCH(ownAddr);
    WATCH(serverAddr);
    WATCH(serverprocId);

    for ( ; ; ) {
        if (hasGUI())
            getDisplayString().setTagArg("i", 1, "");

        // keep an interval between subsequent connections
        wait((double)connectionIaTime);

        if (hasGUI())
            getDisplayString().setTagArg("i", 1, "green");

        // connection setup
        EV << "sending QUIC INITIAL PACKET\n";

        // WYSYLANIE PAKIETU INITIAL Z CRYPTO
        QuicPayload *quicPayload = new QuicPayload();
        QuicFrame *frame = new CryptoFrame();
        quicPayload->addFrame(frame);
        InitialPacket *clientInitialPacket = new InitialPacket(0,0,*quicPayload,0, ownAddr, serverAddr);
        send(clientInitialPacket, "port$o");
        // KONIEC WYSYLANIA INITIAL Z CRYPTO

        EV << "Waiting for Initial[CRYPTO, ACK], Handshake[CRYPTO]";
        InitialPacket *serverInitialPacket = (InitialPacket *)receive(timeout);
        InitialPacket *serverHandshake = (InitialPacket *)receive(timeout);
        InitialPacket *oneRTT = (InitialPacket *)receive(timeout);
        if (serverInitialPacket == nullptr || serverHandshake == nullptr) {
            //goto broken;
        }

        //EV << "got QUIC_INITIAL_SERVER_PACKET "<< serverInitialPacket->getPacketType() << endl;
        //EV << "got QUIC_HANDSHAKE_SERVER_PACKET "<< serverHandshake->getPacketType() << endl;

        if (hasGUI()) {
            getDisplayString().setTagArg("i", 1, "gold");
            bubble("Connected!");
        }

        // Wysylanie potwierdzenia Initial ACK
        QuicPayload *quicPayload2 = new QuicPayload();
        AckFrame *ackFrame2 = new AckFrame();
        quicPayload2->addFrame(ackFrame2);
        InitialPacket *clientInitialPacket2 = new InitialPacket(0,0,*quicPayload2,0, ownAddr, serverAddr);
        clientInitialPacket2->setKind(PacketType::Initial);
        clientInitialPacket2->destAddress = serverAddr;
        clientInitialPacket2->srcAddress = ownAddr;

        QuicPayload *quicPayload3 = new QuicPayload();
        HandshakeDoneFrame *handshakeDoneFrame = new HandshakeDoneFrame();
        quicPayload3->addFrame(handshakeDoneFrame);
        HandshakePacket *handshakeDonePacket= new HandshakePacket(0,0,*quicPayload3,0, ownAddr, serverAddr);
        handshakeDonePacket->setKind(PacketType::Handshake);
        handshakeDonePacket->destAddress = serverAddr;
        handshakeDonePacket->srcAddress = ownAddr;

        QuicPayload *quicPayload4 = new QuicPayload();
        PingFrame *pingFrame4 = new PingFrame();
        AckFrame *ackFrame4 = new AckFrame();
        quicPayload->addFrame(pingFrame4);
        quicPayload->addFrame(ackFrame4);
        QuicPacket *oneRTT4 = new ShortHeaderOneRttPacket(0,0,*quicPayload);
        oneRTT4->srcAddress = ownAddr;
        oneRTT4->destAddress = serverAddr;
        oneRTT4->setKind(PacketType::ZeroRTTProtected);


        send(clientInitialPacket2, "port$o");
        send(handshakeDonePacket, "port$o");
        send(oneRTT4, "port$o");
        (InitialPacket *)receive(timeout);
        (InitialPacket *)receive(timeout);


        actNumQuery = (long)numQuery;
        for (i = 0; i < actNumQuery; i++) {
            EV << "sending DATA(query)\n";
            QuicPayload *quicPayload = new QuicPayload();
            AckFrame *ackFrame = new AckFrame();
            quicPayload->addFrame(ackFrame);
            query = new ShortHeaderOneRttPacket(0,0,*quicPayload);
            query->srcAddress = ownAddr;
            query->destAddress = serverAddr;
            //query->setServerProcId(serverprocId);
            query->setPayload(*quicPayload);
            send(query, "port$o");

            EV << "waiting for DATA(result)\n";
            //answer = (DynaDataPacket *)receive(timeout);
            if (answer == nullptr)
                goto broken;
/*            EV << "got DATA(result)\n";
            delete answer;*/

            wait((double)queryIaTime);
        }

        if (hasGUI())
            getDisplayString().setTagArg("i", 1, "blue");

        // connection teardown
/*        EV << "sending DYNA_DISC_REQ\n";
        discReq = new ShortHeaderOneRttPacket("DYNA_DISC_REQ", DYNA_DISC_REQ);
        discReq->setSrcAddress(ownAddr);
        discReq->setDestAddress(serverAddr);
        discReq->setServerProcId(serverprocId);
        send(discReq, "port$o");

        EV << "waiting for DYNA_DISC_ACK\n";
        discAck = (DynaPacket *)receive(timeout);
        if (discAck == nullptr)
            goto broken;
        EV << "got DYNA_DISC_ACK\n";
        delete discAck;*/

        if (hasGUI())
            bubble("Disconnected!");

        continue;

        // error handling
      broken:
        EV << "Timeout, connection broken!\n";
        if (hasGUI())
            bubble("Connection broken!");
    }
}

