//
// Created by indrek on 14.06.2015.
//

#include "gtest/gtest.h"
#include "Arduino.h"
#include "Bot.h"
#include "mock/MockNodeReader.h"


class SequenceExecutionTest : public ::testing::Test {

protected:

    bool m_isAllDone;
    MockNodeReader m_nodeReader;
    MethodCallback<SequenceExecutionTest> m_doneCallback;


    SequenceExecutionTest() : m_doneCallback(this, &SequenceExecutionTest::allDone)
    {
    }

    virtual void SetUp() {
        arduino_reset_device();
        m_isAllDone = false;
    }



   void runBot(uint32_t time_ms, Bot & bot) {
        for (int i=0; i<time_ms; i++) {
            arduino_increase_millis(1);
            bot.run();
        }
    }


public:
    void allDone() {
        m_isAllDone = true;
    }


};


TEST_F(SequenceExecutionTest, testAllIdleNoCallback) {
    Bot bot(m_nodeReader);
    bot.startExecution(nullptr);
};



TEST_F(SequenceExecutionTest, testAllIdleDone) {
    ASSERT_FALSE(m_isAllDone);
    Bot bot(m_nodeReader);
    bot.startExecution(&m_doneCallback);
    ASSERT_TRUE(m_isAllDone);
};



TEST_F(SequenceExecutionTest, testWaitAction) {

    m_nodeReader.setNodeAction(MAIN_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_5sec);
    m_nodeReader.setNodeAction(MAIN_FIRST_NODE_ID + 5, NodeAction::NODE_ACTION_WAIT_1sec);
    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_5sec);

    ASSERT_FALSE(m_isAllDone);
    Bot bot(m_nodeReader);
    bot.startExecution(&m_doneCallback);
    ASSERT_FALSE(m_isAllDone);
    runBot(5010, bot);
    ASSERT_FALSE(m_isAllDone);
    runBot(900, bot);
    ASSERT_FALSE(m_isAllDone);
    runBot(100, bot);
    ASSERT_TRUE(m_isAllDone);

};



TEST_F(SequenceExecutionTest, testCallOnlySecondSub) {

    m_nodeReader.setNodeAction(MAIN_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_1sec);
    m_nodeReader.setNodeAction(MAIN_FIRST_NODE_ID + 1, NodeAction::NODE_ACTION_CALL_SUB_2);

    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_5sec);
    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID + 1, NodeAction::NODE_ACTION_WAIT_5sec);
    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID + 2, NodeAction::NODE_ACTION_WAIT_5sec);

    m_nodeReader.setNodeAction(SUB_2_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_1sec);

    ASSERT_FALSE(m_isAllDone);
    Bot bot(m_nodeReader);
    bot.startExecution(&m_doneCallback);
    ASSERT_FALSE(m_isAllDone);
    runBot(1990, bot);
    ASSERT_FALSE(m_isAllDone);
    runBot(20, bot);
    ASSERT_TRUE(m_isAllDone);
};



TEST_F(SequenceExecutionTest, testCallBothSubs) {

    m_nodeReader.setNodeAction(MAIN_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_1sec);
    m_nodeReader.setNodeAction(MAIN_FIRST_NODE_ID + 1, NodeAction::NODE_ACTION_CALL_SUB_2);

    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_5sec);
    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID + 1, NodeAction::NODE_ACTION_WAIT_5sec);
    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID + 2, NodeAction::NODE_ACTION_WAIT_5sec);

    m_nodeReader.setNodeAction(SUB_2_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_1sec);
    m_nodeReader.setNodeAction(SUB_2_FIRST_NODE_ID + 1, NodeAction::NODE_ACTION_CALL_SUB_1);

    ASSERT_FALSE(m_isAllDone);
    Bot bot(m_nodeReader);
    bot.startExecution(&m_doneCallback);
    ASSERT_FALSE(m_isAllDone);
    runBot(16990, bot);
    ASSERT_FALSE(m_isAllDone);
    runBot(20, bot);
    ASSERT_TRUE(m_isAllDone);
};



TEST_F(SequenceExecutionTest, testCancelExecution) {

    m_nodeReader.setNodeAction(MAIN_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_1sec);
    m_nodeReader.setNodeAction(MAIN_FIRST_NODE_ID + 1, NodeAction::NODE_ACTION_CALL_SUB_1);

    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_5sec);
    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID + 1, NodeAction::NODE_ACTION_WAIT_5sec);
    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID + 2, NodeAction::NODE_ACTION_WAIT_5sec);
    m_nodeReader.setNodeAction(SUB_1_FIRST_NODE_ID + 3, NodeAction::NODE_ACTION_CALL_SUB_2);

    m_nodeReader.setNodeAction(SUB_2_FIRST_NODE_ID, NodeAction::NODE_ACTION_WAIT_1sec);

    ASSERT_FALSE(m_isAllDone);
    Bot bot(m_nodeReader);
    bot.startExecution(&m_doneCallback);
    ASSERT_FALSE(m_isAllDone);
    runBot(10000, bot);
    ASSERT_FALSE(m_isAllDone);
    bot.cancelExecution();
    runBot(10000, bot);
    ASSERT_FALSE(m_isAllDone);
};
