#ifndef DAAA_IHW_3_DAAA_IHW_3_LIBRARY_EDGE_H_
#define DAAA_IHW_3_DAAA_IHW_3_LIBRARY_EDGE_H_

struct Edge {
    int from, to, cost;

    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {
    }
};

#endif //DAAA_IHW_3_DAAA_IHW_3_LIBRARY_EDGE_H_
