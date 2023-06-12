#include <random>
#include "graph_generator.h"

std::vector<std::vector<int>> generateFullGraph(int count_of_vertices) {
    std::vector<std::vector<int>> graph(count_of_vertices, std::vector<int>(count_of_vertices));

    int cost;
    for (int i = 0; i < count_of_vertices; ++i) {
        for (int j = 0; j < count_of_vertices; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                cost = rand() % 10 + 1;
                graph[i][j] = cost;
                graph[j][i] = cost;
            }
        }
    }

    return graph;
}

std::vector<std::vector<int>> generateTreeGraph(int count_of_vertices) {
    std::vector<std::vector<int>> graph(count_of_vertices, std::vector<int>(count_of_vertices));

    int j = 0, i = 1;
    int cost;
    int counter = 0;

    while (i < count_of_vertices) {
        cost = rand() % 10 + 1;
        graph[i][j] = cost;
        graph[j][i] = cost;
        ++i;
        if (++counter == 2) {
            ++j;
            counter = 0;
        }
    }

    return graph;
}

std::vector<std::vector<int>> generateConnectedGraph(int count_of_vertices) {
    std::vector<std::vector<int>> graph = generateTreeGraph(count_of_vertices);

    int i, j;
    int cost;
    double l = count_of_vertices - 1;

    while (((2 * l) / (count_of_vertices * (count_of_vertices - 1))) < 0.45) {
        i = rand() % count_of_vertices;
        j = rand() % count_of_vertices;
        cost = rand() % 10 + 1;

        while (graph[i][j] != 0 || i == j) {
            i = rand() % count_of_vertices;
            j = rand() % count_of_vertices;
        }

        graph[i][j] = cost;
        graph[j][i] = cost;
        ++l;
    }

    return graph;
}
