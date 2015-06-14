//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEACTION_H
#define PROGRAMMABLEBOT_NODEACTION_H

#include "global.h"
#include "Callback.h"

class NodeAction {

public:

    enum NodeActionType {
        NODE_ACTION_IDLE = 0,
        NODE_ACTION_CALL_SUB,
        NODE_ACTION_WAIT,
        NODE_ACTION_OUTPUT_PIN_ON,
        NODE_ACTION_OUTPUT_PIN_OFF,
        ACTION_COUNT
    };

private:

public:
    virtual void execute(Callback& callback) = 0;

};


#endif //PROGRAMMABLEBOT_NODEACTION_H
