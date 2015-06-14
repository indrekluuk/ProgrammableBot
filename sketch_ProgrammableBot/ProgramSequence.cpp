//
// Created by indrek on 14.06.2015.
//

#include "ProgramSequence.h"
#include "Bot.h"


ProgramSequence::ProgramSequence(
        Bot & bot,
        ProgramNode * nodes,
        uint8_t nodeCount,
        uint8_t firstNodeId
) :
        m_bot(bot),
        m_programNodes(nodes),
        m_nodeCount(nodeCount),
        m_currentNodeIndex(0),
        m_executionSequencer(this, &ProgramSequence::executeNode)
{
    initNodes(firstNodeId);
}

void ProgramSequence::initNodes(uint8_t firstNodeId) {
    for (uint8_t i=0; i<m_nodeCount; i++) {
        m_programNodes[i].initNode(firstNodeId+i);
    }
}

void ProgramSequence::start(Callback *done) {
    m_currentNodeIndex = 0;
    m_executionSequencer.start(done);
}

void ProgramSequence::executeNode(Sequencer &sequencer, uint8_t step) {
    uint8_t nodeIndex = step - (uint8_t)1;
    if (nodeIndex < m_nodeCount) {
        m_bot.executeNode(m_programNodes[nodeIndex], sequencer.nextWhenDone());
    }
}
