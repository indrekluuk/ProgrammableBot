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


};




