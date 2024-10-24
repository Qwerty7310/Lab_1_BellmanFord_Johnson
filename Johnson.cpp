#include "Johnson.h"

#include <iostream>
#include <vector>

#include "BellmanFord.h"
#include "Graph.h"

using namespace std;

int Johnson(int n, int src, vector<Edge> &edges) {
    vector<Edge> new_edges;
    new_edges.reserve(edges.size());
    // Копирование вершин
    for (auto e : edges) new_edges.push_back(e);

    // Добавление новой вершины
    for (int i = 0; i < n; i++) new_edges.push_back({n, i, 0});

    auto *dist = new int[n + 1];
    auto *prev = new int[n + 1];
    if (BellmanFord(n + 1, n, new_edges, dist, prev) == -1) {
        cout << "Цикл с отрицательным весом\n";
        return -1;
    }
    // Изменяем вес ребер, чтобы они были неотрицательными
    for (auto e : new_edges) e.cost = e.cost + dist[e.from] - dist[e.to];

    delete[] dist;
    delete[] prev;

    return 0;
}
