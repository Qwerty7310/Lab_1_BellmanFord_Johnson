#ifndef LAB_1_BELLMAN_FORD_JOHNSON_GRAPH_H
#define LAB_1_BELLMAN_FORD_JOHNSON_GRAPH_H

#include <cstdint>
#include <fstream>

#define INF INT16_MAX

/// Чтение графа
/// \param file входной файл
/// \param n количество вершин
/// \param matrix матрица смежности
void readGraph(std::ifstream &file, int16_t &n, int ***matrix);

#endif  // LAB_1_BELLMAN_FORD_JOHNSON_GRAPH_H
