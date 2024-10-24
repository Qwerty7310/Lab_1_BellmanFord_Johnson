#include "Dijkstra.h"

#include <queue>
#include <vector>
#include <iostream>

#include "Graph.h"

#define INF INT16_MAX

using namespace std;

int Dijkstra(int n, int src, int **matrix, int *dist, int *prev) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, src);

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[src] = 0;

    while (!pq.empty()) {
        auto [cur_dist, u] = pq.top();
        pq.pop();

        if (cur_dist > dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (matrix[u][v] != INF) {
                int new_dist = cur_dist + matrix[u][v];
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    prev[v] = u;
                    pq.emplace(new_dist, v);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << src << " - " << i << ": ";
        if (dist[i] == INF)
            cout << "∞";
        else
            cout << dist[i];
        cout << "\t" << prev[i] << endl;
    }

    return 0;
}