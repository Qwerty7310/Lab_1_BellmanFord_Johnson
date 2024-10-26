#ifndef LAB_1_BELLMAN_FORD_JOHNSON_BELLMANFORD_H
#define LAB_1_BELLMAN_FORD_JOHNSON_BELLMANFORD_H

#include <vector>

#include "Graph.h"

/// Алгоритм Беллмана-Форда
/// \param n размер матрицы
/// \param src начальная вершина
/// \param matrix матриц смежности
/// \param dist массив расстояний
/// \param prev массив предыдущих вершин в кратчайшем пути
/// \return -1 при наличии цикла с отрицательным весом, 0 - при отсутствии
int BellmanFord(int n, int src, int **matrix, int *dist, int *prev);

#endif  // LAB_1_BELLMAN_FORD_JOHNSON_BELLMANFORD_H
