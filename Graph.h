#ifndef LAB_1_BELLMAN_FORD_JOHNSON_GRAPH_H
#define LAB_1_BELLMAN_FORD_JOHNSON_GRAPH_H

#include <cstdint>
#include <fstream>
#include <vector>

#define INF INT16_MAX

struct Edge {
    int from;
    int to;
    int16_t cost;
};

std::vector<Edge> readGraph(std::ifstream &file, int16_t &n);
void readGraph(std::ifstream &file, int16_t &n, int ***matrix);
std::vector<Edge> readGraph2(int16_t matrix[10][10], int16_t &n);
void readGraph3(int matrix[10][10], int16_t &n, int ***matrix1);

#endif  // LAB_1_BELLMAN_FORD_JOHNSON_GRAPH_H
