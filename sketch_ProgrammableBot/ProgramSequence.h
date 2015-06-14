//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_PROGRAMSEQUENCE_H
#define PROGRAMMABLEBOT_PROGRAMSEQUENCE_H

#include "NodeExecutor.h"
#include "Sequencer.h"


class Bot;

class ProgramSequence {

private:
    Bot & m_bot;
    uint8_t m_firstNodeId;
    uint8_t m_nodeCount;
    uint8_t m_currentNodeIndex;

    MethodSequencer<ProgramSequence> m_executionSequencer;

public:
    ProgramSequence(Bot & bot, uint8_t firstNodeId, uint8_t nodeCount);

    void start(Callback* done);

private:

    void executeNode(Sequencer& sequencer, uint8_t step);
    NodeAction::NodeActionType getNodeActionType(uint8_t nodeIndex);
    uint8_t getNodeId(uint8_t nodeIndex);

};




#endif //PROGRAMMABLEBOT_PROGRAMSEQUENCE_H
