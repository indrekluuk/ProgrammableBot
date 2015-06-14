//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEACTION_H
#define PROGRAMMABLEBOT_NODEACTION_H

#include "global.h"
#include "Callback.h"
#include "Scheduler.h"

class NodeAction {

public:

    enum NodeActionType {
        NODE_ACTION_IDLE = 0,
        NODE_ACTION_CALL_SUB_1,
        NODE_ACTION_CALL_SUB_2,
        NODE_ACTION_WAIT_1sec,
        NODE_ACTION_WAIT_5sec,
        NODE_ACTION_OUTPUT_PIN_ON,
        NODE_ACTION_OUTPUT_PIN_OFF,
        ACTION_COUNT
    };

protected:

    static Scheduler m_nodeScheduler;

public:
    virtual void execute(Callback& callback) = 0;

};


#endif //PROGRAMMABLEBOT_NODEACTION_H
