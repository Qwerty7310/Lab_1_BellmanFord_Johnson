#include <iostream>
#include <fstream>
#include <vector>

#include "Edge.h"
#include "BellmanFord.h"

#define INF INT16_MAX

using namespace std;

int main() {
    ifstream file("../tests/matrix_t1_104.txt");

    int16_t matrix[10][10] = {
        INF, 20,INF,16,INF,11,INF,INF,INF,INF,
        INF, INF,6,INF,1,INF,INF,INF,INF,INF,
        INF, INF,INF,INF,INF,INF,5,INF,INF,INF,
        INF, INF,INF,INF,3,INF,INF,9,1,3,
        INF, INF,INF,INF,INF,INF,1,INF,INF,4,
        INF, INF,INF,7,INF,INF,INF,INF,INF,INF,
        INF, INF,INF,INF,INF,INF,INF,INF,INF,2,
        INF, INF,INF,INF,INF,6,INF,INF,INF,INF,
        INF, INF,INF,INF,INF,INF,INF,2,INF,INF,
        INF, INF,INF,INF,INF,INF,INF,INF,5,INF,
    };


    if (!file) {
        cout << "File is not found!\n";
        return 0;
    }

    cout << "OK!\n";

    int n = 0;
    int src = 0;

    vector<Edge> edges = readGraph(file, n);
//    vector<Edge> edges = readGraph2(matrix, n);
    auto *dist = new int[n];
    auto *prev = new int[n];

    BellmanFord(n, src, edges, dist, prev);

    return 0;
}
