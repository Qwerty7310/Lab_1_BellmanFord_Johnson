#ifndef LAB_1_BELLMAN_FORD_JOHNSON__EDGE_H
#define LAB_1_BELLMAN_FORD_JOHNSON__EDGE_H

#include <cstdint>

struct Edge {
    int from;
    int to;
    int16_t cost;
};

#endif  // LAB_1_BELLMAN_FORD_JOHNSON__EDGE_H
