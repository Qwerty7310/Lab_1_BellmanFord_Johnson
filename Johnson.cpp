#include "Johnson.h"

#include <iostream>
#include <vector>

#include "BellmanFord.h"
#include "Dijkstra.h"
#include "Graph.h"

using namespace std;

int Johnson(int n, int **matr_input, int **res) {
    // Создаем новую матрицу с дополнительной вершиной
    int **new_matrix = new int *[n + 1];
    for (int i = 0; i < n + 1; i++) new_matrix[i] = new int[n + 1];

    // Копируем элементы из старой матрицы
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) new_matrix[u][v] = matr_input[u][v];

    // Добавляем новую вершину
    for (int v = 0; v < n + 1; v++) new_matrix[n][v] = 0;
    for (int u = 0; u < n; u++) new_matrix[u][n] = INF;

    auto *dist = new int[n + 1];
    auto *prev = new int[n + 1];
    if (BellmanFord(n + 1, n, new_matrix, dist, prev) == -1) {
        cout << "Цикл с отрицательным весом\n";
        return -1;
    }
    // Изменяем вес ребер, чтобы они были неотрицательными
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) new_matrix[u][v] = new_matrix[u][v] + dist[u] - dist[v];

    delete[] prev;
    prev = new int[n];
    for (int i = 0; i < n; i++) Dijkstra(n, i, new_matrix, res[i], prev);

    // Находим кратчайшие расстояния для исходного графа
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) res[u][v] = res[u][v] - dist[u] + dist[v];

    delete[] dist;
    delete[] prev;

    return 0;
}

void eccentricity(int n, int **matrix, int *res) {
    for (int i = 0; i < n; i++) {
        int max = -INF;
        for (int j = 0; j < n; j++)
            if (matrix[i][j] != INF && matrix[i][j] > max) max = matrix[i][j];
        res[i] = max;
    }
}

int radius(int n, int **matrix) {
    int *arr_eccentricity = new int[n];  // эксцентриситеты вершин
    eccentricity(n, matrix, arr_eccentricity);
    int min = arr_eccentricity[0];
    for (int i = 1; i < n; i++)
        if (arr_eccentricity[i] < min) min = arr_eccentricity[i];

    delete[] arr_eccentricity;
    return min;
}

int diameter(int n, int **matrix) {
    int *arr_eccentricity = new int[n];  // эксцентриситеты вершин
    eccentricity(n, matrix, arr_eccentricity);
    int max = arr_eccentricity[0];
    for (int i = 1; i < n; i++)
        if (arr_eccentricity[i] > max) max = arr_eccentricity[i];

    delete[] arr_eccentricity;
    return max;
}

void vertices(int n, int **matrix, vector<int> &central, vector<int> &peripheral) {
    int rad = radius(n, matrix);     // радиус графа
    int diam = diameter(n, matrix);  // диаметр графа

    int *arr_eccentricity = new int[n];  // эксцентриситеты вершин
    eccentricity(n, matrix, arr_eccentricity);

    for (int i = 0; i < n; i++) {
        if (arr_eccentricity[i] == rad) central.push_back(i);
        if (arr_eccentricity[i] == diam) peripheral.push_back(i);
    }

    delete[] arr_eccentricity;
}