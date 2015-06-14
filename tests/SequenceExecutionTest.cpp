//
// Created by indrek on 14.06.2015.
//

#include "gtest/gtest.h"
#include "Arduino.h"
#include "Bot.h"


class SequenceExecutionTest : public ::testing::Test {

protected:

    bool isAllDone;

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
    Bot bot(nullptr);
};



TEST_F(SequenceExecutionTest, testAllIdleDone) {
    MethodCallback<SequenceExecutionTest> doneCallback(this, &SequenceExecutionTest::allDone);

    ASSERT_FALSE(isAllDone);
    Bot bot(&doneCallback);
    ASSERT_TRUE(isAllDone);
};




