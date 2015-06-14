//
// Created by indrek on 14.06.2015.
//

#include "NodeExecutor.h"

NodeExecutor::NodeExecutor()
{
    for (uint8_t i=0; i<NodeAction::ACTION_COUNT; i++) {
        m_nodeActions[i] = &m_actionIdle;
    }
    m_nodeActions[NodeAction::NODE_ACTION_CALL_SUB] = &m_actionCallSub;
    m_nodeActions[NodeAction::NODE_ACTION_WAIT] = &m_actionWait;
    m_nodeActions[NodeAction::NODE_ACTION_OUTPUT_PIN_ON] = &m_actionOutputPinOn;
    m_nodeActions[NodeAction::NODE_ACTION_OUTPUT_PIN_OFF] = &m_actionOutputPinOff;
}



void NodeExecutor::executeNode(ProgramNode & node, Callback& done) {
    NodeAction * action = m_nodeActions[node.getActionType()];
    action->execute(done);
}

