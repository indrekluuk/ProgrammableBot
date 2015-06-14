//
// Created by indrek on 14.06.2015.
//

#include "NodeActionWait.h"


NodeActionWait::NodeActionWait(uint32_t milliseconds) :
        m_milliseconds(milliseconds)
{
}


void NodeActionWait::execute(Callback &callback) {
    scheduler.set(&callback).runOnce(m_milliseconds);
}

