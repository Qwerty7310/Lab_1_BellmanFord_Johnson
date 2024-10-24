#include <fstream>
#include <iostream>
#include <vector>

#include "BellmanFord.h"
#include "Dijkstra.h"
#include "Graph.h"

#define INF INT16_MAX

using namespace std;

int main() {
//    ifstream file("../tests/matrix_t1_100.txt");
    ifstream file("../tests/bm_t1_109.bm", ios::binary);

    int16_t matr[10][10] = {
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

    int matrix_for_D_FW[10][10] = {
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

    int16_t n = 0;
    int src = 0;

//    vector<Edge> edges = readGraph(file, n);
    int **matrix;
//    readGraph(file, n, &matrix);

    readGraph3(matrix_for_D_FW, n, &matrix);
//    vector<Graph> edges = readGraph2(matrix, n);
    auto *dist = new int[n];
    auto *prev = new int[n];

//    BellmanFord(n, src, edges, dist, prev);
//    BellmanFord(n, src, matrix, dist, prev);
    Dijkstra(n, src, matrix, dist, prev);



    return 0;
}
