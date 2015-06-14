//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEACTIONIDLE_H
#define PROGRAMMABLEBOT_NODEACTIONIDLE_H

#include "NodeAction.h"

class NodeActionIdle : public NodeAction {

public:

    void execute(Callback &callback);
};


#endif //PROGRAMMABLEBOT_NODEACTIONIDLE_H
