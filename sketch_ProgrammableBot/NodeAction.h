//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEACTION_H
#define PROGRAMMABLEBOT_NODEACTION_H

#include "global.h"

class NodeAction {

public:

    static const uint8_t NODE_ACTION_COUNT = 4;

    enum NodeActionType {
        NODE_ACTION_CALL_SUB = 0,
        NODE_ACTION_WAIT = 1,
        NODE_ACTION_OUTPUT_PIN_ON = 2,
        NODE_ACTION_OUTPUT_PIN_OFF = 3
    };

private:

public:
    virtual void execute() = 0;

};


#endif //PROGRAMMABLEBOT_NODEACTION_H
