cmake_minimum_required(VERSION 4.3)
project(Program1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Program1 main.cpp
        List.h
        Player.h
        ArrayList.h
        LinkedList.h
        Node.h
        Data.h)
