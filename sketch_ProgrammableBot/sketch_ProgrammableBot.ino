#include <Scheduler.h>
#include "NodeReader.h"
#include "Bot.h"

HardwareNodeReader nodeReader;
Bot bot(nodeReader, nullptr);

void setup() {
}


void loop() {
  bot.run();
}


