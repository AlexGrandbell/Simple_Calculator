cmake_minimum_required(VERSION 3.25)
project(Simple_Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Simple_Calculator Main.cpp Exception.h Tool.cpp Tool.h SqStack.h LinkStack.h Calculator.cpp Calculator.h Menu.cpp Menu.h)
