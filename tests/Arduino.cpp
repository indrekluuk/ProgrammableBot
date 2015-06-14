/*
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Indrek Luuk (indrek.luuk@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "Arduino.h"
#include "Assert.h"


static const int ARDUINO_PIN_COUNT = 14;
int arduino_digitalWriteCounter_HIGH[ARDUINO_PIN_COUNT];
int arduino_digitalWriteCounter_LOW[ARDUINO_PIN_COUNT];

int arduino_milliseconds = 0;




void arduino_reset_device() {
    arduino_milliseconds = 0;
    for (int i=0; i<ARDUINO_PIN_COUNT; i++) {
        arduino_digitalWriteCounter_HIGH[i] = 0;
        arduino_digitalWriteCounter_LOW[i] = 0;
    }
}

void arduino_increase_millis(unsigned long time_ms) {
    arduino_milliseconds += time_ms;
}

int arduino_get_digitalWrite_HIGH_count(int pin) {
    assert(pin < ARDUINO_PIN_COUNT);
    return arduino_digitalWriteCounter_HIGH[pin];
}

int arduino_get_digitalWrite_LOW_count(int pin) {
    assert(pin < ARDUINO_PIN_COUNT);
    return arduino_digitalWriteCounter_LOW[pin];
}





void pinMode(int pin, int mode) {
}

void digitalWrite(int pin, int val) {
    assert(pin < ARDUINO_PIN_COUNT);
    if (val) {
        arduino_digitalWriteCounter_HIGH[pin]++;
    } else {
        arduino_digitalWriteCounter_LOW[pin]++;
    }
}

unsigned long millis() {
    return arduino_milliseconds;
}


