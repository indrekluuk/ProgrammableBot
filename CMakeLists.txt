cmake_minimum_required(VERSION 3.2)
project(ProgrammableBot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}") #  -std=c++11


include_directories("./frameworks")
include_directories("./sketch_ProgrammableBot")
include_directories("./tests")


set(FRAMEWORK_SOURCE_FILES
        frameworks/gtest/gtest-all.cc)

set(LIBRARY_SOURCE_FILES
        library/Scheduler/Scheduler.cpp
        library/Scheduler/Sequencer.cpp)

set(TEST_SOURCE_FILES
        tests/main.cpp
        tests/Arduino.cpp)


add_executable(ProgrammableBot
        ${FRAMEWORK_SOURCE_FILES}
        ${LIBRARY_SOURCE_FILES}
        ${TEST_SOURCE_FILES}
        sketch_ProgrammableBot/ProgramNode.cpp
        sketch_ProgrammableBot/ProgramNode.h
        sketch_ProgrammableBot/ProgramSequence.cpp
        sketch_ProgrammableBot/ProgramSequence.h
        sketch_ProgrammableBot/Bot.cpp
        sketch_ProgrammableBot/Bot.h)

