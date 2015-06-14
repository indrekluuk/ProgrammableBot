//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_BOT_H
#define PROGRAMMABLEBOT_BOT_H

#include "Constants.h"
#include "ProgramSequence.h"
#include "NodeActionIdle.h"
#include "NodeActionCallSub.h"
#include "NodeActionWait.h"
#include "NodeActionChangeOutputPin.h"

class Bot {

private:

    ProgramSequence m_main;
    ProgramSequence m_sub1;
    ProgramSequence m_sub2;


    NodeActionIdle m_actionIdle;
    NodeActionCallSub m_actionCallSub;
    NodeActionWait m_actionWait;
    NodeActionOutputPinOn m_actionOutputPinOn;
    NodeActionOutputPinOff m_actionOutputPinOff;
    NodeExecutor m_nodeExecutor;


public:

    Bot(Callback * allDone);

    NodeAction::NodeActionType getNodeAction(uint8_t nodeId);
    void executeNode(NodeAction::NodeActionType type, Callback & done);

    void run();



private:

};


#endif //PROGRAMMABLEBOT_BOT_H
