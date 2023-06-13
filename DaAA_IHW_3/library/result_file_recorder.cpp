#include <iostream>
#include "result_file_recorder.h"
#include "graph_generator.h"
#include "test.h"
#include "graph_converter.h"
#include "graph_type.h"

void startProcess() {
    srand(time(NULL));

    std::ofstream viewer_output;
    std::vector<std::vector<int>> initial_graphs[3];

    viewer_output.open("../../../test_view.txt");
    for (int i = 0; i < 3; ++i) {
        switch (i) {
            case 0:
                initial_graphs[i] = generateFullGraph(1010);
                launchGraphViewer(initial_graphs[i], &viewer_output, "Randomized full 1010");
                break;
            case 1:
                initial_graphs[i] = generateTreeGraph(1010);
                launchGraphViewer(initial_graphs[i], &viewer_output, "Randomized tree 1010");
                break;
            case 2:
                initial_graphs[i] = generateConnectedGraph(1010);
                launchGraphViewer(initial_graphs[i], &viewer_output, "Randomized connected 1010");
                break;
            default:break;
        }
    }
    viewer_output.close();

    int debug_line_counter = 0;

    std::ofstream time_output;
    time_output.open("../../../test_time.csv");
    for (int size = 10; size <= 1010; size += 50) {
        for (int graph_type = FULL; graph_type <= CONNECTED; ++graph_type) {
            auto resized_graph = resizeGraph(size, initial_graphs[graph_type]);
            std::string count_of_edges = std::to_string(static_cast<int>(getEdges(resized_graph).size()) / 2);
            std::string info = graph_name[graph_type] + ";" + std::to_string(size) + ";" + count_of_edges + ";";

            std::cout << ++debug_line_counter << ".\t" << info << "\n";

            launchDijkstraTimeChecker(getDijkstraGraph(resized_graph), size, &time_output, info);
            launchBellmanFordChecker(getBellmanFordGraph(resized_graph), size, &time_output, info);
            launchFloydWarshallTimeChecker(getFloydWarshallGraph(resized_graph), size, &time_output, info);
        }
    }
    time_output.close();
}
