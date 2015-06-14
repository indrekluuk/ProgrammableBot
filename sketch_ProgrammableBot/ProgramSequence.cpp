//
// Created by indrek on 14.06.2015.
//

#include "ProgramSequence.h"
#include "Bot.h"


ProgramSequence::ProgramSequence(Bot & bot, uint8_t firstNodeId, uint8_t nodeCount) :
        m_bot(bot),
        m_firstNodeId(firstNodeId),
        m_nodeCount(nodeCount),
        m_currentNodeIndex(0),
        m_executionSequencer(this, &ProgramSequence::executeNode)
{
}


void ProgramSequence::start(Callback * done) {
    m_currentNodeIndex = 0;
    m_executionSequencer.start(done);
}

void ProgramSequence::executeNode(Sequencer &sequencer, uint8_t step) {
    uint8_t nodeIndex = step - (uint8_t)1;
    if (nodeIndex < m_nodeCount) {
        NodeAction::NodeActionType type = getNodeActionType(nodeIndex);
        m_bot.executeNode(type, sequencer.nextWhenDone());
    }
}

NodeAction::NodeActionType ProgramSequence::getNodeActionType(uint8_t nodeIndex) {
    return m_bot.getNodeAction(getNodeId(nodeIndex));
}

uint8_t ProgramSequence::getNodeId(uint8_t nodeIndex) {
    return m_firstNodeId+nodeIndex;
}
