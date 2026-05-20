#pragma once

#include <climits>
#include <iostream>
#include <utility>
#include "LinkQueue.hpp"
#include "LinkStack.hpp"
#include "VecList.hpp"

template <class T>
struct Edge {
    T start;
    T end;
    int weight;
};

template <class T>
class AMGraph {
public:
    int numVer;
    int numEdge;
    VecList<T> verList;
    int** adjMatrix;
    int** originaladjMatrix;
    bool directed;

    AMGraph() {
        numVer = 0;
        numEdge = 0;
        adjMatrix = nullptr;
        originaladjMatrix = nullptr;
        directed = false;
    }

    AMGraph(VecList<T> nodes, int n, bool dir = false) {
        numVer = n;
        numEdge = 0;
        directed = dir;
        for (int i = 0; i < n; i++) {
            verList.insertLast(nodes.getEleAtPos(i));
        }
        adjMatrix = new int*[n];
        originaladjMatrix = new int*[n];
        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new int[n];
            originaladjMatrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0;
                originaladjMatrix[i][j] = 0;
            }
        }
    }

    ~AMGraph() {
        for (int i = 0; i < numVer; i++) {
            delete[] adjMatrix[i];
            delete[] originaladjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] originaladjMatrix;
    }

    void printnodes() const {
        for (int i = 0; i < numVer; i++) {
            std::cout << verList.getEleAtPos(i);
        }
    }

    void addEdge(Edge<T> e) {
        addEdge(e.start, e.end, e.weight);
    }

    void addEdge(T st, T en, int weight) {
        int sIndex = verList.locateEle(st);
        int eIndex = verList.locateEle(en);
        if (sIndex == -1 || eIndex == -1) {
            std::cout << "Wrong Input!" << std::endl;
            return;
        }
        if (adjMatrix[sIndex][eIndex] == 0) numEdge++;
        if (originaladjMatrix[sIndex][eIndex] == 0) {
            originaladjMatrix[sIndex][eIndex] = weight;
            originaladjMatrix[eIndex][sIndex] = weight;
        }
        adjMatrix[sIndex][eIndex] = weight;
        if (!directed) adjMatrix[eIndex][sIndex] = weight;
    }

    void removeEdge(T st, T en) {
        int sIndex = verList.locateEle(st);
        int eIndex = verList.locateEle(en);
        if (sIndex == -1 || eIndex == -1) return;
        if (adjMatrix[sIndex][eIndex] == 0) return;
        numEdge--;
        adjMatrix[sIndex][eIndex] = 0;
        if (!directed) adjMatrix[eIndex][sIndex] = 0;
    }

    int getOriginalWeight(T st, T en) const {
        int sIndex = verList.locateEle(st);
        int eIndex = verList.locateEle(en);
        if (sIndex == -1 || eIndex == -1) return INT_MAX;
        return originaladjMatrix[sIndex][eIndex];
    }

    int** getMatrix() const {
        return adjMatrix;
    }

    int getweight(T a, T b) const {
        int index1 = verList.locateEle(a);
        int index2 = verList.locateEle(b);
        if (index1 == -1 || index2 == -1) return INT_MAX;
        if (adjMatrix[index1][index2] == 0) return INT_MAX;
        return adjMatrix[index1][index2];
    }

    int getposInver(T x) const {
        return verList.locateEle(x);
    }

    void BFShelper(int st, bool* visited) {
        visited[st] = true;
        std::cout << verList.getEleAtPos(st) << " ";
        LinkQueue<int> q;
        q.enQueue(st);
        while (!q.isEmpty()) {
            int tmp = q.deQueue();
            for (int k = 0; k < numVer; k++) {
                if (adjMatrix[tmp][k] == 0) continue;
                if (visited[k]) continue;
                visited[k] = true;
                std::cout << verList.getEleAtPos(k) << " ";
                q.enQueue(k);
            }
        }
    }

    void DFShelper(int st, bool* visited) {
        visited[st] = true;
        std::cout << verList.getEleAtPos(st) << " ";
        for (int k = 0; k < numVer; k++) {
            if (adjMatrix[st][k] == 0) continue;
            if (visited[k]) continue;
            DFShelper(k, visited);
        }
    }

    std::pair<VecList<T>, int> DijkstraTotwopoint(T st, T ed, bool* if_ban, int newlimit, VecList<T> Rootpath) {
        bool* isInS = new bool[numVer];
        int* dist = new int[numVer];
        int* lastNode = new int[numVer];
        int* intermediates = new int[numVer];
        int limit = -1;
        if (newlimit != -1) limit = newlimit - Rootpath.getLength() + 2;

        for (int i = 0; i < numVer; i++) {
            isInS[i] = false;
            dist[i] = INT_MAX;
            lastNode[i] = -1;
            intermediates[i] = 0;
        }

        int sIndex = verList.locateEle(st);
        int eIndex = verList.locateEle(ed);
        if (sIndex == -1 || eIndex == -1 || if_ban[sIndex] || if_ban[eIndex]) {
            delete[] isInS;
            delete[] dist;
            delete[] lastNode;
            delete[] intermediates;
            return std::pair<VecList<T>, int>(VecList<T>(), INT_MAX);
        }

        isInS[sIndex] = true;
        dist[sIndex] = 0;
        for (int i = 0; i < Rootpath.getLength(); i++) {
            int index = verList.locateEle(Rootpath.getEleAtPos(i));
            if (index != -1) isInS[index] = true;
        }
        for (int i = 0; i < numVer; i++) {
            if (if_ban[i]) continue;
            if (adjMatrix[sIndex][i] == 0) continue;
            dist[i] = adjMatrix[sIndex][i];
            lastNode[i] = sIndex;
            intermediates[i] = 1;
        }

        int numInS = 1;
        while (numInS < numVer) {
            int tmpIndex = -1;
            int shortSoFar = -1;
            for (int i = 0; i < numVer; i++) {
                if (isInS[i]) continue;
                if (dist[i] == INT_MAX) continue;
                if (if_ban[i]) continue;
                if (limit != -1 && intermediates[i] > limit) continue;
                if (shortSoFar == -1 || dist[i] < shortSoFar) {
                    tmpIndex = i;
                    shortSoFar = dist[i];
                }
            }
            if (tmpIndex == -1) break;
            isInS[tmpIndex] = true;
            numInS++;
            for (int i = 0; i < numVer; i++) {
                if (if_ban[i]) continue;
                if (isInS[i]) continue;
                if (adjMatrix[tmpIndex][i] == 0) continue;
                int tDist = dist[tmpIndex] + adjMatrix[tmpIndex][i];
                int tIntermediates = intermediates[tmpIndex] + 1;
                if ((dist[i] > tDist) && (limit == -1 || tIntermediates <= limit)) {
                    dist[i] = tDist;
                    lastNode[i] = tmpIndex;
                    intermediates[i] = tIntermediates;
                }
            }
        }

        VecList<T> path;
        int totalDist = INT_MAX;
        if (dist[eIndex] != INT_MAX) {
            LinkStack<int> S;
            S.push(eIndex);
            int j = lastNode[eIndex];
            int count = 0;
            bool* visitedPath = new bool[numVer];
            for (int i = 0; i < numVer; i++) visitedPath[i] = false;

            while (j != -1 && count < numVer) {
                if (j < 0 || j >= numVer) break;
                if (visitedPath[j]) {
                    path.clear();
                    totalDist = INT_MAX;
                    break;
                }
                S.push(j);
                visitedPath[j] = true;
                j = lastNode[j];
                count++;
            }
            delete[] visitedPath;

            if (count < numVer) {
                while (!S.isEmpty()) {
                    int node = S.pop();
                    path.insertLast(verList.getEleAtPos(node));
                }
                totalDist = dist[eIndex];
            }
        }

        delete[] isInS;
        delete[] dist;
        delete[] lastNode;
        delete[] intermediates;
        return std::pair<VecList<T>, int>(path, totalDist);
    }
};

inline void printMatrix(int m, int** arr) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
