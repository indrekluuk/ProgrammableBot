#include <Scheduler.h>
#include "NodeReader.h"
#include "Bot.h"

HardwareNodeReader nodeReader;
Bot bot(nodeReader);

void setup() {
  bot.start(nullptr);
}


void loop() {
  bot.run();
}


