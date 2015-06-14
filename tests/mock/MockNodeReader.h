//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_MOCKNODEREADER_H
#define PROGRAMMABLEBOT_MOCKNODEREADER_H

#include "NodeReader.h"


class MockNodeReader : public NodeReader {

private:
    NodeAction::NodeActionType nodeTypes[TOTAL_NODE_COUNT];


public:
    MockNodeReader() {
        for (int i=0; i<TOTAL_NODE_COUNT; i++) {
            nodeTypes[i] = NodeAction::NODE_ACTION_IDLE;
        }
    }

    void setNodeAction(uint8_t nodeId, NodeAction::NodeActionType type) {
        assert(nodeId < TOTAL_NODE_COUNT);
        nodeTypes[nodeId] = type;
    }

    NodeAction::NodeActionType readNodeAction(uint8_t nodeId) {
        assert(nodeId < TOTAL_NODE_COUNT);
        return nodeTypes[nodeId];
    }
};

#endif //PROGRAMMABLEBOT_MOCKNODEREADER_H

