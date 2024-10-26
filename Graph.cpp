#include "Graph.h"

#include <fstream>
#include <vector>

#define INF INT16_MAX

using namespace std;

vector<Edge> readGraph(ifstream &file, int16_t &n) {
    vector<Edge> edges;
    //    file >> n;
    file.read((char *)&n, sizeof(int16_t));
    for (int16_t i = 0; i < n; i++) {
        for (int16_t j = 0; j < n; j++) {
            int16_t temp;
            //            file >> temp;
            file.read((char *)&temp, sizeof(int16_t));
            if (temp != 0) edges.push_back({i, j, temp});
        }
    }

    return edges;
}

void readGraph(ifstream &file, int16_t &n, int ***matrix) {
    //    file >> n;
    file.read((char *)&n, sizeof(int16_t));
    // Выделение памяти
    (*matrix) = new int *[n];
    for (int i = 0; i < n; i++) {
        (*matrix)[i] = new int[n];
    }

    for (int16_t i = 0; i < n; i++) {
        for (int16_t j = 0; j < n; j++) {
            int16_t temp;
            //            file >> temp;
            file.read((char *)&temp, sizeof(int16_t));
            if (temp != 0)
                (*matrix)[i][j] = temp;
            else
                (*matrix)[i][j] = INF;
        }
    }
}

vector<Edge> readGraph2(int16_t matrix[10][10], int16_t &n) {
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

void readGraph3(int matrix[10][10], int16_t &n, int ***matrix1) {
    n = 10;

    // Выделение памяти
    (*matrix1) = new int *[n];
    for (int i = 0; i < n; i++) {
        (*matrix1)[i] = new int[n];
    }

    for (int16_t i = 0; i < n; i++) {
        for (int16_t j = 0; j < n; j++) {
            (*matrix1)[i][j] = matrix[i][j];
        }
    }
}