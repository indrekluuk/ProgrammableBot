//
// Created by indrek on 14.06.2015.
//

#include "NodeExecutor.h"

NodeExecutor::NodeExecutor(NodeActionIdle & nodeActionIdle)
{
    for (uint8_t i=0; i<NodeAction::ACTION_COUNT; i++) {
        m_nodeActions[i] = &nodeActionIdle;
    }
}

void NodeExecutor::initAction(NodeAction::NodeActionType type, NodeAction &action) {
    m_nodeActions[type] = &action;
}

void NodeExecutor::executeNode(ProgramNode & node, Callback& done) {
    NodeAction * action = m_nodeActions[node.getActionType()];
    action->execute(done);
}

