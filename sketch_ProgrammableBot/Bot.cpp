//
// Created by indrek on 14.06.2015.
//

#include "Bot.h"


Bot::Bot(NodeReader & nodeReader, Callback * allDone) :
        m_nodeReader(nodeReader),
        m_main(*this, MAIN_FIRST_NODE_ID, MAIN_NODE_COUNT),
        m_sub1(*this, SUB_1_FIRST_NODE_ID, SUB_1_NODE_COUNT),
        m_sub2(*this, SUB_2_FIRST_NODE_ID, SUB_2_NODE_COUNT),
        m_nodeExecutor(m_actionIdle),
        m_actionCallSub1(m_sub1),
        m_actionCallSub2(m_sub2),
        m_actionWait5Seconds(5000),
        m_actionWait1Second(1000)
{

    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_CALL_SUB_1, m_actionCallSub1);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_CALL_SUB_2, m_actionCallSub2);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_WAIT_1sec, m_actionWait1Second);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_WAIT_5sec, m_actionWait5Seconds);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_OUTPUT_PIN_ON, m_actionOutputPinOn);
    m_nodeExecutor.initAction(NodeAction::NODE_ACTION_OUTPUT_PIN_OFF, m_actionOutputPinOff);

    m_main.start(allDone);
}




void Bot::executeNode(uint8_t nodeId, Callback & done) {
    m_nodeExecutor.executeNode(getNodeActionType(nodeId), done);
}

NodeAction::NodeActionType Bot::getNodeActionType(uint8_t nodeId) {
    return m_nodeReader.readNodeAction(nodeId);
}


void Bot::run() {
    Scheduler::run();
}


