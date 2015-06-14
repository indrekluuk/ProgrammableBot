//
// Created by indrek on 14.06.2015.
//

#include "NodeActionChangeOutputPin.h"

void NodeActionOutputPinOn::execute(Callback &callback) {
    callback.call();
}

void NodeActionOutputPinOff::execute(Callback &callback) {
    callback.call();
}
