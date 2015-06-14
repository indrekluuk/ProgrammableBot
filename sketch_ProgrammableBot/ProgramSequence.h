//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_PROGRAMSEQUENCE_H
#define PROGRAMMABLEBOT_PROGRAMSEQUENCE_H

#include "ProgramNode.h"
#include "NodeExecutor.h"
#include "Sequencer.h"


class ProgramSequence {

private:
    NodeExecutor& m_nodeExecutor;
    ProgramNode * m_programNodes;
    uint8_t m_nodeCount;
    uint8_t m_currentNodeIndex;

    MethodSequencer<ProgramSequence> m_executionSequencer;

public:
    ProgramSequence(NodeExecutor& nodeExecutor, ProgramNode * nodes, uint8_t nodeCount, uint8_t firstNodeId);

    void start(Callback* done);

private:
    void initNodes(uint8_t firstNodeId);

    void executeNode(Sequencer& sequencer, uint8_t step);

};




#endif //PROGRAMMABLEBOT_PROGRAMSEQUENCE_H
