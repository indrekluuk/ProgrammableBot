//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_PROGRAMSEQUENCE_H
#define PROGRAMMABLEBOT_PROGRAMSEQUENCE_H

#include "ProgramNode.h"


class ProgramSequence {

private:
    ProgramNode * m_programNodes;
    uint8_t m_nodeCount;

public:
    ProgramSequence(ProgramNode * nodes, uint8_t nodeCount, uint8_t firstNodeId);


private:
    void initNodes(uint8_t firstNodeId);
};




#endif //PROGRAMMABLEBOT_PROGRAMSEQUENCE_H
