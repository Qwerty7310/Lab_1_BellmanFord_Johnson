#ifndef LAB_1_BELLMAN_FORD_JOHNSON__BELLMANFORD_H
#define LAB_1_BELLMAN_FORD_JOHNSON__BELLMANFORD_H

#include <cstdint>
#include <fstream>
#include <vector>

#include "Edge.h"

std::vector<Edge> readGraph(std::ifstream &file, int &n);
std::vector<Edge> readGraph2(int16_t matrix[10][10], int &n);
int BellmanFord(int n, int src, std::vector<Edge> &edges, int *dist, int *prev);

#endif  // LAB_1_BELLMAN_FORD_JOHNSON__BELLMANFORD_H
