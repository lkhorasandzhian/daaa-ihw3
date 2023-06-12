#ifndef DAAA_IHW_3_DAAA_IHW_3_LIBRARY_GRAPH_CONVERTER_H_
#define DAAA_IHW_3_DAAA_IHW_3_LIBRARY_GRAPH_CONVERTER_H_

#include <vector>
#include <cstdint>
#include "edge.h"

/// Конвертация базового графа в представление для алгоритма Дейкстры.
std::vector<std::vector<std::pair<int, int64_t>>> getDijkstraGraph(const std::vector<std::vector<int>> &g);

/// Конвертация базового графа в представление для алгоритма Беллмана-Форда.
std::vector<Edge> getBellmanFordGraph(const std::vector<std::vector<int>> &g);

/// Конвертация базового графа в представление для алгоритма Флойда-Уоршелла.
std::vector<std::vector<int64_t>> getFloydWarshallGraph(const std::vector<std::vector<int>> &g);

#endif //DAAA_IHW_3_DAAA_IHW_3_LIBRARY_GRAPH_CONVERTER_H_
