#include <fstream>
#include <iostream>
#include <vector>

#include "BellmanFord.h"
#include "Graph.h"
#include "Johnson.h"
#include "cxxopts.hpp"

#define INF INT16_MAX

using namespace std;

void run(ifstream &input_file, ofstream &output_file);

int main(int argc, char *argv[]) {
    try {
        cxxopts::Options options("Lab_1_Bellman_Ford_Johnson", "Lab1");

        // Определение возможных опций
        options.add_options()("o,output", "Имя выходного файла",
                              cxxopts::value<std::string>()->default_value("default_output.txt"))(
            "input", "Имя входного файла", cxxopts::value<std::string>())("h,help", "Вывод справки");

        // Указываем, что "input" — позиционный аргумент
        options.parse_positional({"input"});

        // Парсим аргументы
        auto result = options.parse(argc, argv);

        // Проверяем, запрошена ли справка
        if (result.count("help")) {
            cout << options.help() << endl;
            return 0;
        }

        // Проверяем наличие обязательного аргумента "input"
        if (!result.count("input")) {
            cerr << "Ошибка: необходим входной файл." << endl;
            return 1;
        }

        // Получаем значения аргументов
        string input_file = result["input"].as<string>();
        string output_file = result["output"].as<string>();

        // Ваш основной код с использованием входного и выходного файлов
        ifstream input(input_file, ios::binary);
        if (!input.is_open()) {
            cerr << "Ошибка: не удается открыть входной файл " << input_file << endl;
            return 1;
        }

        ofstream output(output_file);
        if (!output.is_open()) {
            cerr << "Ошибка: не удается открыть выходной файл " << output_file << endl;
            return 1;
        }

        run(input, output);

    } catch (const std::exception &e) {
        cerr << "Ошибка при разборе аргументов: " << e.what() << endl;
        return 1;
    }

    return 0;
}

void run(ifstream &input, ofstream &output) {
    int16_t n = 0;

    int **matrix;  // Матрица смежности
    readGraph(input, n, &matrix);

    int src = 0;
    int *dist = new int[n];
    int *pred = new int[n];
    if (BellmanFord(n, src, matrix, dist, pred) == -1) {
        output << "Цикл с отрицательным весом" << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        output << 0 << " - " << i << ": ";
        if (dist[i] == INF)
            output << "∞" << endl;
        else
            output << dist[i] << endl;
    }

    delete[] dist;
    delete[] pred;

    // Матрица кратчайших расстояний
    int **shortest_dist = new int *[n];
    for (int i = 0; i < n; i++) shortest_dist[i] = new int[n];
    Johnson(n, matrix, shortest_dist);

    int diam = diameter(n, shortest_dist);
    int rad = radius(n, shortest_dist);

    vector<int> central, peripheral;
    vertices(n, shortest_dist, central, peripheral);

    output << diam << " " << rad << endl;
    for (auto v : central) output << v << " ";
    output << endl;
    for (auto v : peripheral) output << v << " ";
    output << endl;

    for (int i = 0; i < n; i++) delete[] shortest_dist[i];
    delete[] shortest_dist;
}
