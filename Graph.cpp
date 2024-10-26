#include "Graph.h"

#include <fstream>

#define INF INT16_MAX

using namespace std;

void readGraph(ifstream &file, int16_t &n, int ***matrix) {
    //    file >> n;
    file.read((char *)&n, sizeof(int16_t));
    // Выделение памяти
    (*matrix) = new int *[n];
    for (int i = 0; i < n; i++) (*matrix)[i] = new int[n];

    for (int16_t i = 0; i < n; i++)
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
