//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEACTIONCALLSUB_H
#define PROGRAMMABLEBOT_NODEACTIONCALLSUB_H

#include "NodeAction.h"
#include "ProgramSequence.h"

class NodeActionCallSub : public NodeAction {

private:

    ProgramSequence & m_programSequence;

public:

    NodeActionCallSub(ProgramSequence & programSequence);

    void execute(Callback &callback);

};


#endif //PROGRAMMABLEBOT_NODEACTIONCALLSUB_H
