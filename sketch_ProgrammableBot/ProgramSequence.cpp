//
// Created by indrek on 14.06.2015.
//

#include "ProgramSequence.h"
#include "Bot.h"


ProgramSequence::ProgramSequence(Bot & bot, uint8_t firstNodeId, uint8_t nodeCount) :
        m_bot(bot),
        m_firstNodeId(firstNodeId),
        m_nodeCount(nodeCount),
        m_executionSequencer(this, &ProgramSequence::executeNode)
{
}


void ProgramSequence::start(Callback * done) {
    m_executionSequencer.start(done);
}

void ProgramSequence::stop() {
    m_executionSequencer.stop();
}

void ProgramSequence::executeNode(Sequencer &sequencer, uint8_t step) {
    uint8_t nodeIndex = step - (uint8_t)1;
    if (nodeIndex < m_nodeCount) {
        m_bot.executeNode(getNodeId(nodeIndex), sequencer.nextWhenDone());
    }
}

uint8_t ProgramSequence::getNodeId(uint8_t nodeIndex) {
    return m_firstNodeId+nodeIndex;
}

