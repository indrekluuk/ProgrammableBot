//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_BOT_H
#define PROGRAMMABLEBOT_BOT_H

#include "Constants.h"
#include "NodeReader.h"
#include "ProgramSequence.h"
#include "NodeActionIdle.h"
#include "NodeActionCallSub.h"
#include "NodeActionWait.h"
#include "NodeActionChangeOutputPin.h"

class Bot {

private:

    NodeReader & m_nodeReader;

    ProgramSequence m_main;
    ProgramSequence m_sub1;
    ProgramSequence m_sub2;


    NodeActionIdle m_actionIdle;
    NodeActionCallSub m_actionCallSub1;
    NodeActionCallSub m_actionCallSub2;
    NodeActionWait m_actionWait5Seconds;
    NodeActionWait m_actionWait1Second;
    NodeActionOutputPinOn m_actionOutputPinOn;
    NodeActionOutputPinOff m_actionOutputPinOff;
    NodeExecutor m_nodeExecutor;


public:

    Bot(NodeReader & nodeReader, Callback * allDone);

    void executeNode(uint8_t nodeId, Callback & done);

    void run();



private:

    NodeAction::NodeActionType getNodeActionType(uint8_t nodeId);

};


#endif //PROGRAMMABLEBOT_BOT_H
