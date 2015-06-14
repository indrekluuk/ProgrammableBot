//
// Created by indrek on 14.06.2015.
//

#include "Bot.h"


Bot::Bot(Callback * allDone) :
        m_main(*this, MAIN_FIRST_NODE_ID, MAIN_NODE_COUNT),
        m_sub1(*this, SUB_1_FIRST_NODE_ID, SUB_1_NODE_COUNT),
        m_sub2(*this, SUB_2_FIRST_NODE_ID, SUB_2_NODE_COUNT),
        m_nodeExecutor(m_actionIdle)
{

    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_CALL_SUB, m_actionCallSub);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_WAIT, m_actionWait);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_OUTPUT_PIN_ON, m_actionOutputPinOn);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_OUTPUT_PIN_OFF, m_actionOutputPinOff);

    m_main.start(allDone);
}




void Bot::executeNode(uint8_t nodeId, Callback & done) {
    m_nodeExecutor.executeNode(getNodeActionType(nodeId), done);
}

NodeAction::NodeActionType Bot::getNodeActionType(uint8_t nodeId) {
    return NodeAction::NODE_ACTION_IDLE;
}


void Bot::run() {
    Scheduler::run();
}


