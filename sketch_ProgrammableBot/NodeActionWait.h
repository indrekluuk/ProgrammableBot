//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEACTIONWAIT_H
#define PROGRAMMABLEBOT_NODEACTIONWAIT_H

#include "NodeAction.h"


class NodeActionWait : public NodeAction {

private:
    uint32_t m_milliseconds;


public:

    NodeActionWait(uint32_t milliseconds);

    virtual void execute(Callback &callback);
};


#endif //PROGRAMMABLEBOT_NODEACTIONWAIT_H
