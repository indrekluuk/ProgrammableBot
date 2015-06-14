//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEEXECUTOR_H
#define PROGRAMMABLEBOT_NODEEXECUTOR_H

#include "Callback.h"
#include "ProgramNode.h"


class NodeExecutor {


public:

    void executeNode(ProgramNode& node, Callback& done);

};


#endif //PROGRAMMABLEBOT_NODEEXECUTOR_H
