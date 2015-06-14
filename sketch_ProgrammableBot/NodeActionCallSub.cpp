//
// Created by indrek on 14.06.2015.
//

#include "NodeActionCallSub.h"


NodeActionCallSub::NodeActionCallSub(ProgramSequence &programSequence) : m_programSequence(programSequence) {
}



void NodeActionCallSub::execute(Callback &callback) {
    m_programSequence.start(&callback);
}

