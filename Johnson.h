#ifndef LAB_1_BELLMAN_FORD_JOHNSON_JOHNSON_H
#define LAB_1_BELLMAN_FORD_JOHNSON_JOHNSON_H

#include <vector>

/// \param n количество вершин
/// \param matr_input матрица смежности
/// \param res матрица кратчайших расстояний
/// \return -1 - присутствует цикл с отрицательным весом, 0 - в другом случае
int Johnson(int n, int **matr_input, int **res);

/// Нахождение эксцентриситетов вершин
/// \param n количество вершин
/// \param matrix матрица кратчайших расстояний
/// \param res массив результатов
void eccentricity(int n, const int **matrix, int *res);

/// Радиус графа
/// \param n количество вершин
/// \param matrix матрица смежности
/// \return радиус графа
int radius(int n, int **matrix);

/// Диаметр графа
/// \param n количество вершин
/// \param matrix матрица смежности
/// \return диаметр графа
int diameter(int n, int **matrix);

/// Центральные и периферийные вершины
/// \param n количество вершин
/// \param matrix матрица смежности
/// \param central вектор центральных вершин
/// \param peripheral вектор периферийных вершин
void vertices(int n, int **matrix, std::vector<int> &central, std::vector<int> &peripheral);

#endif  // LAB_1_BELLMAN_FORD_JOHNSON_JOHNSON_H
