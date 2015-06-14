//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_BOT_H
#define PROGRAMMABLEBOT_BOT_H

#include "Constants.h"
#include "ProgramSequence.h"


class Bot {

private:
    ProgramNode m_mainNodes[MAIN_NODE_COUNT];
    ProgramNode m_sub1Nodes[SUB_1_NODE_COUNT];
    ProgramNode m_sub2Nodes[SUB_2_NODE_COUNT];

    ProgramSequence m_main;
    ProgramSequence m_sub1;
    ProgramSequence m_sub2;


public:
    Bot();


    void run();

private:

};


#endif //PROGRAMMABLEBOT_BOT_H
