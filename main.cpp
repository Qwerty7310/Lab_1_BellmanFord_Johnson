#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <fstream>

int main() {
    // Определение графа с помощью Boost Graph Library
    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;

    // Создаем граф с 5 вершинами
    Graph g(5);

    // Добавляем ребра между вершинами
    boost::add_edge(0, 1, g);
    boost::add_edge(0, 2, g);
    boost::add_edge(1, 3, g);
    boost::add_edge(1, 4, g);

    // Открываем файл для записи в формате DOT
    std::ofstream dotFile("graph.dot");

    // Записываем граф в формате DOT
    boost::write_graphviz(dotFile, g);

    std::cout << "Граф записан в файл graph.dot" << std::endl;
    std::cout << "Теперь используйте Graphviz для визуализации." << std::endl;

    return 0;
}
