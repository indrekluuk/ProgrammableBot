//
// Created by indrek on 14.06.2015.
//

#include "ProgramNode.h"


ProgramNode::ProgramNode() :
        m_id(ID_NOT_INITIALIZED)
{

}

void ProgramNode::initNode(uint8_t id) {
    m_id = id;
}
