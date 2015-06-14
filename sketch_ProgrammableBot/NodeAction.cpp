//
// Created by indrek on 14.06.2015.
//

#include "NodeAction.h"

Scheduler NodeAction::m_nodeScheduler;

void NodeAction::stop() {
    m_nodeScheduler.stop();
}
