cmake_minimum_required(VERSION 3.25)
project(DaAA_IHW_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(DaAA_IHW_3 main.cpp
        library/searching_algorithms.cpp library/searching_algorithms.h
        library/graph_generator.cpp library/graph_generator.h
        library/result_file_recorder.cpp library/result_file_recorder.h
        library/test.cpp library/test.h
        library/unit_test.cpp library/unit_test.h
        library/graph_converter.cpp library/graph_converter.h
        library/edge.h
        library/graph_type.h)