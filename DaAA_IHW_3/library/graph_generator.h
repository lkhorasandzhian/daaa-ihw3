#ifndef DAAA_IHW_3_DAAA_IHW_3_LIBRARY_GRAPH_GENERATOR_H_
#define DAAA_IHW_3_DAAA_IHW_3_LIBRARY_GRAPH_GENERATOR_H_

#include <vector>

/// Создаёт полный граф.
std::vector<std::vector<int>> generateFullGraph(int count_of_vertices);

/// Создаёт разреженный граф.
std::vector<std::vector<int>> generateTreeGraph(int count_of_vertices);

/// Создаёт связный граф.
std::vector<std::vector<int>> generateConnectedGraph(int count_of_vertices);

#endif //DAAA_IHW_3_DAAA_IHW_3_LIBRARY_GRAPH_GENERATOR_H_
