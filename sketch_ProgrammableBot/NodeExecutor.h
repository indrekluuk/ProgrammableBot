

//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEEXECUTOR_H
#define PROGRAMMABLEBOT_NODEEXECUTOR_H

#include "Callback.h"
#include "ProgramNode.h"
#include "NodeAction.h"
#include "NodeActionIdle.h"


class NodeExecutor {

private:

    NodeActionIdle m_actionIdle;
    NodeAction * m_nodeActions[NodeAction::ACTION_COUNT];

public:

    NodeExecutor();
    void initAction(NodeAction::NodeActionType type, NodeAction* action);

    void executeNode(ProgramNode& node, Callback& done);

};


#endif //PROGRAMMABLEBOT_NODEEXECUTOR_H
