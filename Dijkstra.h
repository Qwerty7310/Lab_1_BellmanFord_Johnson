#ifndef LAB_1_BELLMAN_FORD_JOHNSON_DIJKSTRA_H
#define LAB_1_BELLMAN_FORD_JOHNSON_DIJKSTRA_H

/// Алгоритм Дейкстры
/// \param n количество вершин
/// \param src исходная вершина
/// \param matrix матрица смежности
/// \param dist массив кратчайших расстояний
/// \param prev массив предыдущих вершин в кратчайшем пути
/// \return ничего
void Dijkstra(int n, int src, int **matrix, int *dist, int *prev);

#endif  // LAB_1_BELLMAN_FORD_JOHNSON_DIJKSTRA_H
