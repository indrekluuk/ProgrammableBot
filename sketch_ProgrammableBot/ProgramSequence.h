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

    MethodSequencer<ProgramSequence> m_executionSequencer;

public:
    ProgramSequence(Bot & bot, uint8_t firstNodeId, uint8_t nodeCount);

    void start(Callback* done);
    void stop();

private:

    void executeNode(Sequencer& sequencer, uint8_t step);
    uint8_t getNodeId(uint8_t nodeIndex);

};




#endif //PROGRAMMABLEBOT_PROGRAMSEQUENCE_H
