//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

//do zmiany
#include "DynaPacket_m.h"
#include "quic/model/packets/QuicPacket.h"
#include "quic/model/packets/LongHeaderPacket.h"
#include "quic/model/packets/PacketType.h"
#include "quic/model/packets/InitialPacket.h"
#include "quic/model/packets/ShortHeaderOneRttPacket.h"
#include "quic/model/frames/HandshakeDoneFrame.h"
using namespace omnetpp;

/**
 * The server computer; see NED file for more info
 */
class Server : public cSimpleModule
{
  private:
    cModuleType *srvProcType;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Server);

void Server::initialize()
{
    srvProcType = cModuleType::find("ServerProcess");
}

void Server::handleMessage(cMessage *msg)
{
    // rzutowanie na QuicPacket
    QuicPacket *pk = check_and_cast<QuicPacket *>(msg);

    // Initial packet recieved
    if (pk->getKind() == PacketType::Initial) {
        LongHeaderPacket *pk1 = check_and_cast<LongHeaderPacket *>(msg);
        QuicFrame *frame = pk1->quicPayload.frames.front();
        if(frame->getFirstFrameType() == FrameType::ACK) {
            QuicPayload *quicPayload3 = new QuicPayload();
            AckFrame *ackFrame = new AckFrame();
            quicPayload3->addFrame(ackFrame);
            InitialPacket *handshake= new InitialPacket(0,0,*quicPayload3,0, pk->srcAddress, pk->destAddress);
            handshake->setKind(PacketType::Handshake);
            handshake->srcAddress = pk->destAddress;
            handshake->destAddress = pk->srcAddress;

            QuicPayload *quicPayload = new QuicPayload();
            HandshakeDoneFrame *handshakeDoneFrame = new HandshakeDoneFrame();
            quicPayload->addFrame(handshakeDoneFrame);
            QuicPacket *handshakeDonePacket = new ShortHeaderOneRttPacket(0,0,*quicPayload);
            handshakeDonePacket->srcAddress = pk->destAddress;
            handshakeDonePacket->destAddress = pk->srcAddress;
            handshakeDonePacket->setKind(PacketType::ZeroRTTProtected);

            sendDirect(handshake, gate("port$o"));
            sendDirect(handshakeDonePacket, gate("port$o"));


        } else {
            // wyslac do clienta Initial (ACK), Pusty handshake i 1-RTT
            cModule *mod = srvProcType->createScheduleInit("serverproc", this);
            //EV << "DYNA_CONN_REQ: Created process ID=" << mod->getId() << endl;
            sendDirect(pk, mod, "in");
        }

    }
    // Dane
    else {
        /*//int serverProcId = pk->getServerProcId();
        //EV << "Redirecting msg to process ID=" << serverProcId << endl;
        //cModule *mod = getSimulation()->getModule(serverProcId);
        if (!mod) {
            EV << " That process already exited, deleting msg\n";
            delete pk;
        }
        else {
            sendDirect(pk, mod, "in");
        }*/

        //send do klienta 1-RTT

    }
}

