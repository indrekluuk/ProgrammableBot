//
// Created by indrek on 14.06.2015.
//

#include "Bot.h"


Bot::Bot() :
        m_main(*this, m_mainNodes, MAIN_NODE_COUNT, MAIN_FIRST_NODE_ID),
        m_sub1(*this, m_sub1Nodes, SUB_1_NODE_COUNT, SUB_1_FIRST_NODE_ID),
        m_sub2(*this, m_sub2Nodes, SUB_2_NODE_COUNT, SUB_2_FIRST_NODE_ID),
        m_nodeExecutor(m_actionIdle)
{

    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_CALL_SUB, m_actionCallSub);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_WAIT, m_actionWait);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_OUTPUT_PIN_ON, m_actionOutputPinOn);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_OUTPUT_PIN_OFF, m_actionOutputPinOff);

    m_main.start(nullptr);
}



void Bot::executeNode(ProgramNode & node, Callback & done) {
    m_nodeExecutor.executeNode(node, done);
}



void Bot::run() {
    Scheduler::run();
}


