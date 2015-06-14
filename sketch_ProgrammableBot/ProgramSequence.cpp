//
// Created by indrek on 14.06.2015.
//

#include "ProgramSequence.h"



ProgramSequence::ProgramSequence(ProgramNode * nodes, uint8_t nodeCount, uint8_t firstNodeId) :
        m_programNodes(nodes),
        m_nodeCount(nodeCount)
{
    initNodes(firstNodeId);
}

void ProgramSequence::initNodes(uint8_t firstNodeId) {
    for (uint8_t i=0; i<m_nodeCount; i++) {
        m_programNodes[i].initNode(firstNodeId+i);
    }
}
