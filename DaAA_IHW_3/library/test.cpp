#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>
#include "test.h"
#include "searching_algorithms.h"

const int count_of_repeats = 5;

void launchGraphViewer(const std::vector<std::vector<int>> &initial_graph, std::ofstream *output, const std::string &info) {
    *output << info << ":\n";
    for (size_t i = 0; i < initial_graph.size(); ++i) {
        for (size_t j = 0; j < initial_graph[i].size(); ++j) {
            *output << i << " " << j << " " << initial_graph[i][j] << "\n";
        }
    }
    *output << "\n\n";
}

void launchDijkstraTimeChecker(const std::vector<std::vector<std::pair<int, int64_t>>> &initial_graph, int graph_size, std::ofstream *output, const std::string &info) {
    long long nanoseconds;

    *output << info << "Dijkstra-PQ;";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        auto _ = searchDijkstraPq(graph_size, initial_graph);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";

    *output << info << "Dijkstra-Set;";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        auto _ = searchDijkstraSet(graph_size, initial_graph);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";
}

void launchBellmanFordChecker(const std::vector<Edge> &initial_graph, int graph_size, std::ofstream *output, const std::string &info) {
    long long nanoseconds;

    *output << info << "Bellman-Ford;";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        auto _ = searchBellmanFord(graph_size, initial_graph);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";
}

void launchFloydWarshallTimeChecker(const std::vector<std::vector<int64_t>> &initial_graph, int graph_size, std::ofstream *output, const std::string &info) {
    long long nanoseconds;

    *output << info << "Floyd-Warshall;";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        auto _ = searchFloydWarshall(graph_size, initial_graph);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / count_of_repeats << "\n";
}
