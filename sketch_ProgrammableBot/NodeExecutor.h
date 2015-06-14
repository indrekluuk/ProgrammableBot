

//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEEXECUTOR_H
#define PROGRAMMABLEBOT_NODEEXECUTOR_H

#include "Callback.h"
#include "ProgramNode.h"
#include "NodeActionIdle.h"
#include "NodeActionCallSub.h"
#include "NodeActionWait.h"
#include "NodeActionChangeOutputPin.h"

class NodeExecutor {

private:

    NodeActionIdle m_actionIdle;
    NodeActionCallSub m_actionCallSub;
    NodeActionWait m_actionWait;
    NodeActionOutputPinOn m_actionOutputPinOn;
    NodeActionOutputPinOff m_actionOutputPinOff;

    NodeAction * m_nodeActions[NodeAction::ACTION_COUNT];

public:
    NodeExecutor();
    void executeNode(ProgramNode & node, Callback& done);
};


#endif //PROGRAMMABLEBOT_NODEEXECUTOR_H
