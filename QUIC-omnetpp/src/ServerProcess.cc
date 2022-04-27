//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//


// do wyrzucenia
#include "DynaPacket_m.h"
#include "quic/model/packets/PacketType.h"
#include "quic/model/packets/QuicPacket.h"
#include "quic/model/packets/HandshakePacket.h"
#include "quic/model/packets/ShortHeaderOneRttPacket.h"
#include "quic/model/frames/QuicFrame.h"

using namespace omnetpp;

#define STACKSIZE    16384

/**
 * Dynamically launched process in the server; see NED file for more info
 */
class ServerProcess : public cSimpleModule
{
  public:
    ServerProcess() : cSimpleModule(STACKSIZE) {}
    virtual void activity() override;
};

Define_Module(ServerProcess);

void ServerProcess::activity()
{
    // retrieve parameters
    cPar& processingTime = getParentModule()->par("processingTime");

    cGate *serverOutGate = getParentModule()->gate("port$o");

    int clientAddr = 0, ownAddr = 0;
    WATCH(clientAddr);
    WATCH(ownAddr);

    QuicPacket *pk;
    QuicPacket *datapk;

    // receive the CONN_REQ we were created to handle
    EV << "Started, waiting for CLIENT INITIAL\n";
    pk = (QuicPacket *)receive();
    clientAddr = pk->srcAddress;
    ownAddr = pk->destAddress;

    // set the module name to something informative
    char buf[30];
    sprintf(buf, "serverproc%d-clientaddr%d", getId(), clientAddr);
    setName(buf);

    // respond to CLIENT INITIAL with INITIAL[CRYPTO, ACK]
    EV << "client is addr=" << clientAddr << ", sending QUIC_INITIAL_PACKET\n";
    QuicPacket *serverInitial = new QuicPacket();
    serverInitial->setName("QUIC_INITIAL_PACKET");
    serverInitial->setKind(PacketType::Initial);
    serverInitial->srcAddress = ownAddr;
    serverInitial->destAddress = clientAddr;
    serverInitial->addFrame(new CryptoFrame());
    serverInitial->addFrame(new AckFrame());

    QuicPacket *serverHandshake = new QuicPacket();
    serverHandshake->setName("QUIC_HANDSHAKE_PACKET");
    serverHandshake->setKind(PacketType::Handshake);
    serverHandshake->srcAddress = ownAddr;
    serverHandshake->destAddress = clientAddr;
    serverHandshake->addFrame(new CryptoFrame());

    QuicPayload *quicPayload = new QuicPayload();
    PingFrame *pingFrame = new PingFrame();
    quicPayload->addFrame(pingFrame);
    QuicPacket *oneRTT = new ShortHeaderOneRttPacket(0,0,*quicPayload);
    oneRTT->srcAddress = pk->destAddress;
    oneRTT->destAddress = pk->srcAddress;
    oneRTT->setKind(PacketType::ZeroRTTProtected);
    sendDirect(serverInitial, serverOutGate);
    sendDirect(serverHandshake, serverOutGate);
    sendDirect(oneRTT, serverOutGate);

    // Process requests until QUIC qill teardown connection
    for ( ; ; ) {
        EV << "waiting for DATA(query) (or CONNECTION_CLOSE)\n";
        pk = (QuicPacket *)receive();
        int type = pk->getKind();


        // Quic connection disconnected
        if (type == CONNECTION_CLOSE)
            break;

        if (type == HANDSHAKE_DONE){
            datapk = (HandshakePacket *) pk;

            wait((double)processingTime);
            EV << "client is addr=" << clientAddr << ", sending QUIC_HANDSHAKE\n";
            datapk->setName("QUIC_HANDSHAKE");
            datapk->setKind(PacketType::Handshake);
            datapk->srcAddress = ownAddr;
            datapk->destAddress = clientAddr;
                //pk->setServerProcId(getId());
            sendDirect(datapk, serverOutGate);
        }
    }

    // connection teardown in response to DISC_REQ
/*    EV << "got DYNA_DISC_REQ, sending DYNA_DISC_ACK\n";
    pk->setName("DYNA_DISC_ACK");
    pk->setKind(DYNA_DISC_ACK);
    pk->setSrcAddress(ownAddr);
    pk->setDestAddress(clientAddr);
    sendDirect(pk, serverOutGate);*/

    EV << "exiting\n";
    deleteModule();
}

