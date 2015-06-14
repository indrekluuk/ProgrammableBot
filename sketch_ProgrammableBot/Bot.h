//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_BOT_H
#define PROGRAMMABLEBOT_BOT_H

#include "Constants.h"
#include "ProgramSequence.h"
#include "NodeActionCallSub.h"
#include "NodeActionWait.h"
#include "NodeActionChangeOutputPin.h"


class Bot {

private:
    ProgramNode m_mainNodes[MAIN_NODE_COUNT];
    ProgramNode m_sub1Nodes[SUB_1_NODE_COUNT];
    ProgramNode m_sub2Nodes[SUB_2_NODE_COUNT];

    ProgramSequence m_main;
    ProgramSequence m_sub1;
    ProgramSequence m_sub2;


    NodeActionCallSub m_actionCallSub;
    NodeActionWait m_actionWait;
    NodeActionOutputPinOn m_actionOutputPinOn;
    NodeActionOutputPinOff m_actionOutputPinOff;
    NodeExecutor m_nodeExecutor;


public:
    Bot();

    void run();

private:

};


#endif //PROGRAMMABLEBOT_BOT_H
