#ifndef DAAA_IHW_3_DAAA_IHW_3_LIBRARY_GRAPH_TYPE_H_
#define DAAA_IHW_3_DAAA_IHW_3_LIBRARY_GRAPH_TYPE_H_

/// \b FULL - Randomized full 1010.\n
/// \b TREE - Randomized tree 1010.\n
/// \b CONNECTED - Randomized connected 1010.\n
enum GraphType {
    FULL,
    TREE,
    CONNECTED
};

const std::string graph_name[3] = {
    "Full",
    "Tree",
    "Connected",
};

#endif //DAAA_IHW_3_DAAA_IHW_3_LIBRARY_GRAPH_TYPE_H_
