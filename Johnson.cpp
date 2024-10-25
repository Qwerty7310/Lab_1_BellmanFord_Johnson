#include "Johnson.h"

#include <iostream>
#include <vector>

#include "BellmanFord.h"
#include "Dijkstra.h"
#include "Graph.h"

using namespace std;

int Johnson(int n, int **matr_input, int **res) {
    // Добавление новой вершины
    int **new_matrix = new int *[n + 1];
    for (int i = 0; i < n + 1; i++) new_matrix[i] = new int[n + 1];

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            new_matrix[u][v] = matr_input[u][v];
        }
    }
    for (int v = 0; v < n + 1; v++) new_matrix[n][v] = 0;
    for (int u = 0; u < n; u++) new_matrix[u][n] = INF;

    auto *dist = new int[n + 1];
    auto *prev = new int[n + 1];
    if (BellmanFord(n + 1, n, new_matrix, dist, prev) == -1) {
        cout << "Цикл с отрицательным весом\n";
        return -1;
    }
    // Изменяем вес ребер, чтобы они были неотрицательными
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            new_matrix[u][v] = new_matrix[u][v] + dist[u] - dist[v];
        }
    }

    delete[] prev;
    prev = new int[n];
    for (int i = 0; i < n; i++) {
        Dijkstra(n, i, new_matrix, res[i], prev);
    }

    // Находим кратчайшие расстояния для исходного графа
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            res[u][v] = res[u][v] - dist[u] + dist[v];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << 0 << " - " << i << ": ";
        if (res[0][i] == INF)
            cout << "∞" << endl;
        else
            cout << res[0][i] << endl;
    }

    delete[] dist;
    delete[] prev;

    return 0;
}
