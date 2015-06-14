//
// Created by indrek on 14.06.2015.
//

#include "Bot.h"


Bot::Bot() :
        m_main(m_nodeExecutor, m_mainNodes, MAIN_NODE_COUNT, MAIN_FIRST_NODE_ID),
        m_sub1(m_nodeExecutor, m_sub1Nodes, SUB_1_NODE_COUNT, SUB_1_FIRST_NODE_ID),
        m_sub2(m_nodeExecutor, m_sub2Nodes, SUB_2_NODE_COUNT, SUB_2_FIRST_NODE_ID)
{

    m_nodeExecutor.initAction(NodeExecutor::NODE_ACTION_CALL_SUB, &m_actionCallSub);
    m_nodeExecutor.initAction(NodeExecutor::NODE_aCTION_WAIT, &m_actionWait);
    m_nodeExecutor.initAction(NodeExecutor::NODE_ACTION_OUTPUT_PIN_ON, &m_actionOutputPinOn);
    m_nodeExecutor.initAction(NodeExecutor::NODE_ACTION_OUTPUT_PIN_OFF, &m_actionOutputPinOff);

    m_main.start(nullptr);
}

void Bot::run() {
    Scheduler::run();
}
