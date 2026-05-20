#pragma once

#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include "Graph.hpp"

template <class T>
class Solution {
public:
    AMGraph<T> G;
    bool* if_ban;
    int limit;
    VecList<VecList<T>> paths;
    VecList<int> totalweights;
    int nodesnum;
    VecList<T> nodes;
    int edgesnum;

    Solution(int m, int n, VecList<T> strings, std::vector<Edge<T>> edges)
        : G(strings, m) {
        nodesnum = m;
        edgesnum = n;
        if_ban = new bool[nodesnum];
        for (int i = 0; i < nodesnum; i++) {
            nodes.insertLast(strings.getEleAtPos(i));
            if_ban[i] = false;
        }
        limit = -1;
        for (int i = 0; i < n; i++) {
            G.addEdge(edges[i]);
        }
    }

    ~Solution() {
        delete[] if_ban;
    }

    bool if_In(VecList<T> path) const {
        for (int i = 0; i < paths.getLength(); i++) {
            if (paths.getEleAtPos(i) == path) return true;
        }
        return false;
    }

    int getpathweight(VecList<T> path) const {
        int pathweight = 0;
        for (int i = 0; i < path.getLength() - 1; i++) {
            int w = G.getweight(path.getEleAtPos(i), path.getEleAtPos(i + 1));
            if (w == INT_MAX) return INT_MAX;
            if (pathweight > INT_MAX - w) return INT_MAX;
            pathweight += w;
        }
        return pathweight;
    }

    int getminpath(VecList<VecList<T>> pathsTopick) const {
        if (pathsTopick.isEmpty()) return -1;
        int minweight = getpathweight(pathsTopick.getEleAtPos(0));
        int pos = 0;
        for (int i = 1; i < pathsTopick.getLength(); i++) {
            int currentWeight = getpathweight(pathsTopick.getEleAtPos(i));
            if (currentWeight < minweight) {
                minweight = currentWeight;
                pos = i;
            }
        }
        return pos;
    }

    void addpath(VecList<T> path, int weight) {
        if (if_In(path) || path.isEmpty() || weight == INT_MAX) return;
        if (paths.isEmpty()) {
            paths.insertLast(path);
            totalweights.insertLast(weight);
            return;
        }

        int pos = 0;
        while (pos < totalweights.getLength() && totalweights.getEleAtPos(pos) < weight) {
            pos++;
        }
        paths.insertEleAtPos(pos, path);
        totalweights.insertEleAtPos(pos, weight);
    }

    void minpaths(T start, T end, int K) {
        paths.clear();
        totalweights.clear();

        std::pair<VecList<T>, int> firstPathPair = G.DijkstraTotwopoint(start, end, if_ban, limit, VecList<T>());
        if (firstPathPair.second == INT_MAX) {
            std::cout << "没有找到从 " << start << " 到 " << end << " 的路径。" << std::endl;
            return;
        }

        VecList<T> firstPath = firstPathPair.first;
        int firstWeight = firstPathPair.second;
        addpath(firstPath, firstWeight);

        auto comparator = [](const std::pair<VecList<T>, int>& a, const std::pair<VecList<T>, int>& b) {
            return a.second > b.second;
        };
        std::priority_queue<
            std::pair<VecList<T>, int>,
            std::vector<std::pair<VecList<T>, int>>,
            decltype(comparator)> B(comparator);

        VecList<VecList<T>> A_paths;
        A_paths.insertLast(firstPath);

        for (int k = 1; k < K; ++k) {
            VecList<T> currentPath = A_paths.getEleAtPos(A_paths.getLength() - 1);
            int pathLen = currentPath.getLength();
            for (int j = 0; j < pathLen - 1; ++j) {
                T spurNode = currentPath.getEleAtPos(j);
                VecList<T> rootPath;
                for (int m = 0; m <= j; ++m) {
                    rootPath.insertLast(currentPath.getEleAtPos(m));
                }

                std::vector<std::pair<T, T>> removedEdges;
                for (int p = 0; p < paths.getLength(); ++p) {
                    VecList<T> existingPath = paths.getEleAtPos(p);
                    bool sharePrefix = true;
                    for (int m = 0; m <= j; ++m) {
                        if (existingPath.getEleAtPos(m) != rootPath.getEleAtPos(m)) {
                            sharePrefix = false;
                            break;
                        }
                    }
                    if (sharePrefix && existingPath.getLength() > j + 1) {
                        T edgeEnd = existingPath.getEleAtPos(j + 1);
                        G.removeEdge(spurNode, edgeEnd);
                        removedEdges.emplace_back(std::make_pair(spurNode, edgeEnd));
                    }
                }

                std::pair<VecList<T>, int> spurPathPair = G.DijkstraTotwopoint(spurNode, end, if_ban, limit, rootPath);
                if (spurPathPair.second != INT_MAX) {
                    VecList<T> spurPath = spurPathPair.first;
                    VecList<T> totalPath = rootPath;
                    bool hasCycle = false;
                    for (int n = 1; n < spurPath.getLength(); ++n) {
                        if (totalPath.contains(spurPath.getEleAtPos(n))) {
                            hasCycle = true;
                            break;
                        }
                        totalPath.insertLast(spurPath.getEleAtPos(n));
                    }
                    if (!hasCycle && !totalPath.isEmpty()) {
                        int totalWeight = getpathweight(totalPath);
                        if (!if_In(totalPath)) {
                            B.push(std::make_pair(totalPath, totalWeight));
                        }
                    }
                }

                for (int edge = 0; edge < static_cast<int>(removedEdges.size()); edge++) {
                    int weight = G.getOriginalWeight(removedEdges[edge].first, removedEdges[edge].second);
                    if (weight != INT_MAX) {
                        G.addEdge(removedEdges[edge].first, removedEdges[edge].second, weight);
                    }
                }
            }

            bool found = false;
            while (!B.empty()) {
                std::pair<VecList<T>, int> candidate = B.top();
                B.pop();
                if (!if_In(candidate.first)) {
                    addpath(candidate.first, candidate.second);
                    A_paths.insertLast(candidate.first);
                    std::cout << "选择路径 " << (k + 1) << "，权重：" << candidate.second << std::endl;
                    found = true;
                    break;
                }
            }

            if (!found) break;
        }

        std::cout << "找到 " << paths.getLength() << " 条路径：" << std::endl;
        for (int i = 0; i < paths.getLength(); ++i) {
            std::cout << "路径 " << (i + 1) << ": ";
            for (int j = 0; j < paths.getEleAtPos(i).getLength(); ++j) {
                std::cout << paths.getEleAtPos(i).getEleAtPos(j);
                if (j != paths.getEleAtPos(i).getLength() - 1) std::cout << "->";
            }
            std::cout << ", 总权重 = " << totalweights.getEleAtPos(i) << std::endl;
        }
    }
};
