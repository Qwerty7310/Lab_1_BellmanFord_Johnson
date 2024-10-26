#include "BellmanFord.h"

#include <climits>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

#include "Graph.h"

using namespace std;

int BellmanFord(int n, int src, vector<Edge> &edges, int *dist, int *prev) {
    // Инициализация массива
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[src] = 0;

    bool flag_negative_cycle = false;
    for (int i = 0; i < n; i++) {  // Цикл (|V| - 1) раз + 1 раз для проверки на отрицательный цикл
        bool flag_change = false;
        // Для каждой пары (u, v)
        for (auto e : edges) {
            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                prev[e.to] = e.from;
                flag_change = true;
            }
        }
        if (!flag_change)
            break;
        else if (i == n - 1)
            flag_negative_cycle = true;
    }

    if (flag_negative_cycle) {
        cout << "Негативный цикл\n";
        return -1;
    }

    for (int i = 0; i < n; i++) {
        cout << src << " - " << i << ": ";
        if (dist[i] == INF)
            cout << "∞" << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}

int BellmanFord(int n, int src, int **matrix, int *dist, int *prev) {
    // Инициализация массива
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[src] = 0;

    bool flag_negative_cycle = false;
    for (int i = 0; i < n; i++) {  // Цикл (|V| - 1) раз + 1 раз для проверки на отрицательный цикл
        bool flag_change = false;
        // Для каждой пары (u, v)
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dist[u] != INF && dist[v] > dist[u] + matrix[u][v]) {
                    dist[v] = dist[u] + matrix[u][v];
                    prev[v] = u;
                    flag_change = true;
                }
            }
        }
        if (!flag_change)
            break;
        else if (i == n - 1)
            flag_negative_cycle = true;
    }

    if (flag_negative_cycle) {
        cout << "Цикл с отрицательным весом\n";
        return -1;
    }

    return 0;
}
