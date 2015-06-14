//
// Created by indrek on 14.06.2015.
//

#include "gtest/gtest.h"
#include "Arduino.h"
#include "Bot.h"
#include "mock/MockNodeReader.h"


class SequenceExecutionTest : public ::testing::Test {

protected:

    bool isAllDone;
    MockNodeReader nodeReader;

    virtual void SetUp() {
        arduino_reset_device();
        isAllDone = false;
    }



   void runBot(uint32_t time_ms, Bot & bot) {
        for (int i=0; i<time_ms; i++) {
            arduino_increase_millis(1);
            bot.run();
        }
    }


public:
    void allDone() {
        isAllDone = true;
    }


};


TEST_F(SequenceExecutionTest, testAllIdleNoCallback) {
    Bot bot(nodeReader, nullptr);
};



TEST_F(SequenceExecutionTest, testAllIdleDone) {
    MethodCallback<SequenceExecutionTest> doneCallback(this, &SequenceExecutionTest::allDone);

    ASSERT_FALSE(isAllDone);
    Bot bot(nodeReader, &doneCallback);
    ASSERT_TRUE(isAllDone);
};



TEST_F(SequenceExecutionTest, testWaitAction) {
    MethodCallback<SequenceExecutionTest> doneCallback(this, &SequenceExecutionTest::allDone);

    nodeReader.setNodeAction(MAIN_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_5sec);
    nodeReader.setNodeAction(MAIN_FIRST_NODE_ID + 5, NodeAction::NODE_ACTION_WAIT_1sec);
    nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_5sec);

    ASSERT_FALSE(isAllDone);
    Bot bot(nodeReader, &doneCallback);
    ASSERT_FALSE(isAllDone);
    runBot(5010, bot);
    ASSERT_FALSE(isAllDone);
    runBot(900, bot);
    ASSERT_FALSE(isAllDone);
    runBot(100, bot);
    ASSERT_TRUE(isAllDone);

};




