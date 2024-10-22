#include "BellmanFord.h"

#include <climits>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

#include "Edge.h"

#define INF INT16_MAX

using namespace std;

vector<Edge> readGraph(ifstream &file, int &n) {
    vector<Edge> edges;
    file >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int16_t temp;
            file >> temp;
            if (temp != 0) edges.push_back({i, j, temp});
        }
    }

    return edges;
}

vector<Edge> readGraph2(int16_t matrix[10][10], int &n) {
    n = 10;
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int16_t temp = matrix[i][j];
            if (temp != INF) edges.push_back({i, j, temp});
        }
    }

    return edges;
}

int BellmanFord(int n, int src, vector<Edge> &edges, int *dist, int *prev) {
    //    auto *dist = new int[n];  // Массив расстояний
    //    auto *prev = new int[n];
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

int Johnson(int n, int src, vector<Edge> &edges) {
    return 0;
}