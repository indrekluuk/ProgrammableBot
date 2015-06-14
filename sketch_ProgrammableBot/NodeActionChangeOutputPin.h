//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_NODEACTIONCHANGEOUTPUTPIN_H
#define PROGRAMMABLEBOT_NODEACTIONCHANGEOUTPUTPIN_H

#include "NodeAction.h"


class NodeActionChangeOutputPin : public NodeAction {

};


class NodeActionOutputPinOn : public NodeActionChangeOutputPin {

public:
    void execute();

};


class NodeActionOutputPinOff : public NodeActionChangeOutputPin {

public:
    void execute();

};



#endif //PROGRAMMABLEBOT_NODEACTIONCHANGEOUTPUTPIN_H
