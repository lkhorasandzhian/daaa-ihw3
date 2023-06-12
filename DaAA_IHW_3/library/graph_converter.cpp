#include "graph_converter.h"

/// Конвертация базового графа в представление для алгоритма Дейкстры.
std::vector<std::vector<std::pair<int, int64_t>>> getDijkstraGraph(const std::vector<std::vector<int>> &g) {
    std::vector<std::vector<std::pair<int, int64_t>>> dijkstra_graph(g.size());

    for (size_t i = 0; i < g.size(); ++i) {
        for (size_t j = 0; j < g.size(); ++j) {
            if (i != j && g[i][j] != 0) {
                dijkstra_graph[i].emplace_back(j, g[i][j]);
            }
        }
    }

    return dijkstra_graph;
}

/// Конвертация базового графа в представление для алгоритма Беллмана-Форда.
std::vector<Edge> getBellmanFordGraph(const std::vector<std::vector<int>> &g) {
    std::vector<Edge> bellman_ford_graph;

    for (size_t i = 0; i < g.size(); ++i) {
        for (size_t j = i; j < g.size(); ++j) {
            if (i != j && g[i][j] != 0) {
                bellman_ford_graph.emplace_back(i, j, g[i][j]);
            }
        }
    }

    return bellman_ford_graph;
}

/// Конвертация базового графа в представление для алгоритма Флойда-Уоршелла.
std::vector<std::vector<int64_t>> getFloydWarshallGraph(const std::vector<std::vector<int>> &g) {
    std::vector<std::vector<int64_t>> floyd_warshall_graph(g.size(), std::vector<int64_t>(g.size()));

    for (size_t i = 0; i < g.size(); ++i) {
        for (size_t j = 0; j < g.size(); ++j) {
            floyd_warshall_graph[i][j] = g[i][j];
        }
    }

    return floyd_warshall_graph;
}
