#ifndef DAAA_IHW_3_DAAA_IHW_3_LIBRARY_TEST_H_
#define DAAA_IHW_3_DAAA_IHW_3_LIBRARY_TEST_H_

#include "edge.h"
#include <fstream>

/// Вывод в файл сгенерированных исходных текстов.
void launchGraphViewer(const std::vector<std::vector<int>> &initial_graph, std::ofstream *output, const std::string &info);

/// Вывод в файл замера времени работы алгоритма Дейкстры.
void launchDijkstraTimeChecker(const std::vector<std::vector<std::pair<int, int64_t>>> &initial_graph, int graph_size, std::ofstream *output, const std::string &info);

/// Вывод в файл замера времени работы алгоритма Беллмана-Форда.
void launchBellmanFordChecker(const std::vector<Edge> &initial_graph, int graph_size, std::ofstream *output, const std::string &info);

/// Вывод в файл замера времени работы алгоритма Флойда-Уоршелла.
void launchFloydWarshallTimeChecker(const std::vector<std::vector<int64_t>> &initial_graph, int graph_size, std::ofstream *output, const std::string &info);

#endif //DAAA_IHW_3_DAAA_IHW_3_LIBRARY_TEST_H_
