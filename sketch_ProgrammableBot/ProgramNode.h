//
// Created by indrek on 14.06.2015.
//

#ifndef PROGRAMMABLEBOT_PROGRAMNODE_H
#define PROGRAMMABLEBOT_PROGRAMNODE_H

#include "global.h"


class ProgramNode {

private:
    static const  uint8_t ID_NOT_INITIALIZED = 255;
    uint8_t m_id;

public:
    ProgramNode();

    void initNode(uint8_t id);

};


#endif //PROGRAMMABLEBOT_PROGRAMNODE_H
