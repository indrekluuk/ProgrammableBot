//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEEXECUTOR_H
#define PROGRAMMABLEBOT_NODEEXECUTOR_H

#include "Callback.h"
#include "ProgramNode.h"
#include "NodeAction.h"


class NodeExecutor {

public:

    static const uint8_t NODE_ACTION_COUNT = 4;

    enum NodeActionType {
        NODE_ACTION_CALL_SUB = 0,
        NODE_aCTION_WAIT = 1,
        NODE_ACTION_OUTPUT_PIN_ON = 2,
        NODE_ACTION_OUTPUT_PIN_OFF = 3
    };

private:

    NodeAction * m_nodeActions[NODE_ACTION_COUNT];

public:

    NodeExecutor();
    void initAction(NodeActionType type, NodeAction* action);

    void executeNode(ProgramNode& node, Callback& done);

};


#endif //PROGRAMMABLEBOT_NODEEXECUTOR_H
