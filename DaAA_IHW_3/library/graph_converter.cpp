#include "graph_converter.h"

std::vector<std::vector<int>> resizeGraph(int request, const std::vector<std::vector<int>> &old_g) {
    std::vector<std::vector<int>> new_g(request, std::vector<int>(request));

    for (int i = 0; i < request; ++i) {
        for (int j = 0; j < request; ++j) {
            new_g[i][j] = old_g[i][j];
        }
    }

    return new_g;
}

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

std::vector<Edge> getBellmanFordGraph(const std::vector<std::vector<int>> &g) {
    std::vector<Edge> bellman_ford_graph;

    for (size_t i = 0; i < g.size(); ++i) {
        for (size_t j = 0; j < g.size(); ++j) {
            if (i != j && g[i][j] != 0) {
                bellman_ford_graph.emplace_back(i, j, g[i][j]);
            }
        }
    }

    return bellman_ford_graph;
}

std::vector<std::vector<int64_t>> getFloydWarshallGraph(const std::vector<std::vector<int>> &g) {
    std::vector<std::vector<int64_t>> floyd_warshall_graph(g.size(), std::vector<int64_t>(g.size()));

    for (size_t i = 0; i < g.size(); ++i) {
        for (size_t j = 0; j < g.size(); ++j) {
            floyd_warshall_graph[i][j] = g[i][j];
        }
    }

    return floyd_warshall_graph;
}

std::vector<Edge> getEdges(const std::vector<std::vector<int>> &g) {
    return getBellmanFordGraph(g);
}
