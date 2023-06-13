#ifndef DAAA_IHW_3_DAAA_IHW_3_LIBRARY_SEARCHING_ALGORITHMS_H_
#define DAAA_IHW_3_DAAA_IHW_3_LIBRARY_SEARCHING_ALGORITHMS_H_

#include <vector>
#include <cstdint>
#include "edge.h"

/// Алгоритм Дейкстры на очереди с приоритетом.
int64_t searchDijkstraPq(int destination, const std::vector<std::vector<std::pair<int, int64_t>>> &g);

/// Алгоритм Дейкстры на сете.
int64_t searchDijkstraSet(int destination, const std::vector<std::vector<std::pair<int, int64_t>>> &g);

/// Алгоритм Беллмана-Форда.
int64_t searchBellmanFord(int destination, const std::vector<Edge> &edges);

/// Алгоритм Флойда-Уоршелла.
int64_t searchFloydWarshall(int destination, std::vector<std::vector<int64_t>> d);

#endif //DAAA_IHW_3_DAAA_IHW_3_LIBRARY_SEARCHING_ALGORITHMS_H_
