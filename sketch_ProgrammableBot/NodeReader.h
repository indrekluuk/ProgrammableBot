//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEREADER_H
#define PROGRAMMABLEBOT_NODEREADER_H

#include "NodeAction.h"



class NodeReader {

public:
    
    virtual NodeAction::NodeActionType readNodeAction(uint8_t nodeId) = 0;

};


class HardwareNodeReader : public NodeReader {

public:

    NodeAction::NodeActionType readNodeAction(uint8_t nodeId);

};


#endif //PROGRAMMABLEBOT_NODEREADER_H
