//
// Created by indrek on 14.06.2015.
//

#include "NodeExecutor.h"

NodeExecutor::NodeExecutor()
{
    for (uint8_t i=0; i<NODE_ACTION_COUNT; i++) {
        m_nodeActions[i] = nullptr;
    }
}


void NodeExecutor::initAction(NodeExecutor::NodeActionType type, NodeAction *action) {
    m_nodeActions[type] = action;
}


void NodeExecutor::executeNode(ProgramNode &node, Callback& done) {

}

