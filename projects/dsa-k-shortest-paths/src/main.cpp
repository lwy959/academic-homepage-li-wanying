#include <iostream>
#include <string>
#include <vector>
#include "../include/KShortestPaths.hpp"

int main() {
    int m = 0, n = 0;
    std::cin >> m >> n;
    if (m < 0 || n < 0) {
        std::cout << "顶点和边数必须为非负整数" << std::endl;
        return 0;
    }

    VecList<char> strings;
    for (int i = 0; i < m; i++) {
        char node;
        std::cin >> node;
        strings.insertLast(node);
    }

    std::vector<Edge<char>> edges;
    for (int i = 0; i < n; i++) {
        char s1;
        char s2;
        int w;
        std::cin >> s1 >> s2 >> w;
        Edge<char> edge;
        edge.start = s1;
        edge.end = s2;
        edge.weight = w;
        edges.push_back(edge);
        if (!strings.contains(s1) || !strings.contains(s2)) {
            std::cout << "输入了错误字串" << std::endl;
        }
    }

    Solution<char> solver(m, n, strings, edges);
    std::string command;
    while (std::cin >> command) {
        if (command == "ban") {
            char s;
            std::cin >> s;
            int pos = solver.nodes.locateEle(s);
            if (pos == -1) {
                std::cout << "节点不存在" << std::endl;
            } else {
                solver.if_ban[pos] = true;
            }
        } else if (command == "unban") {
            char s;
            std::cin >> s;
            int pos = solver.nodes.locateEle(s);
            if (pos == -1) {
                std::cout << "节点不存在" << std::endl;
            } else {
                solver.if_ban[pos] = false;
            }
        } else if (command == "maxTrans") {
            int y;
            std::cin >> y;
            solver.limit = (y >= 0) ? y : -1;
        } else if (command == "paths") {
            char start;
            char end;
            int k;
            std::cin >> start >> end >> k;
            solver.minpaths(start, end, k);
        } else if (command == "quit") {
            return 0;
        } else {
            std::cout << "未知指令：" << command << std::endl;
        }
    }

    return 0;
}
