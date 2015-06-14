cmake_minimum_required(VERSION 3.2)
project(ProgrammableBot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}") #  -std=c++11


include_directories("./frameworks")
include_directories("./library/Scheduler")
include_directories("./sketch_ProgrammableBot")
include_directories("./tests")


set(FRAMEWORK_SOURCE_FILES
        frameworks/gtest/gtest-all.cc)

set(LIBRARY_SOURCE_FILES
        library/Scheduler/Scheduler.cpp
        library/Scheduler/Sequencer.cpp)

set(TEST_SOURCE_FILES
        tests/main.cpp
        tests/Arduino.cpp
        tests/SequenceExecutionTest.cpp
        tests/mock/MockNodeReader.h)


add_executable(ProgrammableBot
        ${FRAMEWORK_SOURCE_FILES}
        ${LIBRARY_SOURCE_FILES}
        ${TEST_SOURCE_FILES}
        sketch_ProgrammableBot/ProgramSequence.cpp
        sketch_ProgrammableBot/ProgramSequence.h
        sketch_ProgrammableBot/Bot.cpp
        sketch_ProgrammableBot/Bot.h
        sketch_ProgrammableBot/NodeExecutor.cpp
        sketch_ProgrammableBot/NodeExecutor.h
        sketch_ProgrammableBot/NodeAction.cpp
        sketch_ProgrammableBot/NodeAction.h
        sketch_ProgrammableBot/NodeActionCallSub.cpp
        sketch_ProgrammableBot/NodeActionCallSub.h
        sketch_ProgrammableBot/NodeActionChangeOutputPin.cpp
        sketch_ProgrammableBot/NodeActionChangeOutputPin.h
        sketch_ProgrammableBot/NodeActionWait.cpp
        sketch_ProgrammableBot/NodeActionWait.h
        sketch_ProgrammableBot/NodeActionIdle.cpp
        sketch_ProgrammableBot/NodeActionIdle.h
        sketch_ProgrammableBot/NodeReader.cpp
        sketch_ProgrammableBot/NodeReader.h)

