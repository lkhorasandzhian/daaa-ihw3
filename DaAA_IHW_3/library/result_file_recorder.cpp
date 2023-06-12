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

    std::ofstream time_output;
    time_output.open("../../../test_time.csv");
    for (int size = 10; size <= 1010; size += 50) {
        for (int graph_type = FULL; graph_type <= CONNECTED; ++graph_type) {
            launchDijkstraTimeChecker(getDijkstraGraph(initial_graphs[graph_type]), size, &time_output, "Full;" + std::to_string(size) + ";");
            launchBellmanFordChecker(getBellmanFordGraph(initial_graphs[graph_type]), size, &time_output, "Tree;" + std::to_string(size) + ";");
            launchFloydWarshallTimeChecker(getFloydWarshallGraph(initial_graphs[graph_type]), size, &time_output, "Connected;" + std::to_string(size) + ";");
        }
    }
    time_output.close();
}
