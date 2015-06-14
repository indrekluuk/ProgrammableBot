

//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEEXECUTOR_H
#define PROGRAMMABLEBOT_NODEEXECUTOR_H

#include "Callback.h"
#include "NodeActionIdle.h"


class NodeExecutor {

private:


    NodeAction * m_nodeActions[NodeAction::ACTION_COUNT];

public:
    NodeExecutor(NodeActionIdle & nodeActionIdle);
    void initAction(NodeAction::NodeActionType type, NodeAction & action);
    void executeNode(NodeAction::NodeActionType type, Callback& done);
};


#endif //PROGRAMMABLEBOT_NODEEXECUTOR_H
