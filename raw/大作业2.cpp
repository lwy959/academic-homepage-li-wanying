// 大作业2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include <iomanip>
#include<string>
#include<limits.h>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include <unordered_set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <functional>

using namespace std;

template <class T>
class VecList {
private:
    int capacity;
    int length;
    T* arr;
    void doubleListSize() {
        T* oldArr = arr;
        arr = new T[2 * capacity];
        capacity = 2 * capacity;
        for (int i = 0; i < length; i++) {
            arr[i] = oldArr[i];
        }
        delete[] oldArr;
    }
public:
    VecList() {
        length = 0;
        capacity = 100;
        arr = new T[capacity];
    }
    VecList(T* a, int n) {
        length = n;
        capacity = 100 + 2 * n;
        arr = new T[capacity];
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }
    }
    VecList(const VecList<T>& other) : capacity(other.capacity), length(other.length), arr(new T[other.capacity]) {
        for (int i = 0; i < other.length; i++) {
            arr[i] = other.arr[i];
        }
    }
    VecList<T>& operator=(const VecList<T>& other) {
        if (this != &other) {
            // 释放当前资源
            delete[] arr;

            // 复制基本数据
            capacity = other.capacity;
            length = other.length;

            // 分配新内存并复制元素
            arr = new T[capacity];
            for (int i = 0; i < length; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    bool operator==(const VecList<T>&other) {
        if (length != other.length) return false;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] != other.arr[i]) return false;
        }
        return true ;
    }
    ~VecList() {
        delete[] arr;
    }
    bool contains(const T& element) const {
        for (int i = 0; i < length; i++) {
            if (arr[i] == element)
                return true;
        }
        return false;
    }

    int getLength() {
        return length;
    }
    bool isEmpty() {
        return length == 0;
    }
    void clear() 
    { length = 0; }
    void insertEleAtPos(int i, T x) {
        if (length == capacity)
            doubleListSize();
        if (i > length || i < 0)
            throw "Illegal position";
        for (int j = length; j > i; j--)
            arr[j] = arr[j - 1];
        arr[i] = x;
        length++;
    }
    T deleteEleAtPos(int i) {
        if (i >= length || i < 0) 
            throw "Illegal position";
        T tmp = arr[i];
        for (int j = i; j < length - 1; j++)
            arr[j] = arr[j + 1];
        length--;
        return tmp;
    }
    void setEleAtPos(int i, T x) {
        if (i >= length || i < 0)
            throw "Illegal position";
        arr[i] = x;
    }
    T getEleAtPos(int i) {
        if (i >= length || i < 0)
            throw "Illegal position";
        return arr[i];
    }
    int locateEle(T x) {
        for (int i = 0; i < length; i++) {
            if (arr[i] == x)
                return i;
        }
        return -1;
    }
    void insertLast(T x) {
        insertEleAtPos(length, x);
    }
    void printList() {
        for (int i = 0; i < length; i++)
            cout << arr[i] << " ";
    }
};

template <class T>
struct DNode {
    T data;
    DNode<T>* next;
};

template <class T>
class LinkStack {
private:
    DNode<T>* top;
    int length;
public:
    LinkStack() {
        top = NULL;
        length = 0;
    }
    ~LinkStack() {
        while (top != NULL) {
            DNode<T>* tmp = top;
            top = top->next;
            delete tmp;
        }
    }
    int getLength() {
        return length;
    }
    bool isEmpty() {
        return length == 0;
    }
    void clear() { length = 0; }
    void push(T x) {
        DNode<T>* tmp = new DNode<T>;
        tmp->data = x;
        tmp->next = top;
        top = tmp;
        length++;
    }
    T pop() {
        if (length == 0) throw "Stack Empty!";
        DNode<T>* tmp = top;
        top = top->next;
        T tmpData = tmp->data;
        delete tmp;
        length--;
        return tmpData;
    }
    T getTop() {
        if (length == 0) throw "Stack Empty!";
        return top->data;
    }
    void printStack() {
        cout << "Stack top: ";
        DNode<T>* tmp = top;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << ":stack bottom" << endl;
    }
};

template <class T>
class LinkQueue {
private:
    DNode<T>* front;
    DNode<T>* back;
    int length;
public:
    LinkQueue() {
        front = new DNode<T>;
        front->next = NULL;
        back = front;
        length = 0;
    }
    ~LinkQueue() {
        while (front != NULL) {
            back = front;
            front = front->next;
            delete back;
        }
    }
    int getLength() {
        return length;
    }
    bool isEmpty() {
        return length == 0;
    }
    void enQueue(T x) {
        DNode<T>* tmpN = new DNode<T>;
        tmpN->data = x;
        tmpN->next = NULL;
        back->next = tmpN;
        back = tmpN;
        length++;
    }
    T deQueue() {
        if (length == 0) throw "Queue Empty!";
        DNode<T>* tmpN = front->next;
        front->next = tmpN->next;
        T tmpD = tmpN->data;
        delete tmpN;
        length--;
        if (length == 0) back = front;
        return tmpD;
    }
    T peekQueue() {
        if (length == 0) throw "Queue Empty!";
        return front->next->data;
    }
    void printQueue() {
        cout << "Front of queue: ";
        DNode<T>* tmp = front->next;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << ": back of queue" << endl;
    }
};

template <class T>
struct Edge {
    T start;
    T end;
    int weight;
};
template <class T>
class AMGraph { //we need the number of vertices fixed if we are using this approach
    //our edges don't contain weights here.
public:
    int numVer, numEdge;
    VecList<T> verList; // list of vertices
    int** adjMatrix;
    int** originaladjMatrix;
    bool directed;
    vector<vector<int>> adjList;
    void BFShelper(int st, bool* visited) {
        visited[st] = true;
        cout << verList.getEleAtPos(st) << " ";
        LinkQueue<int> q;
        q.enQueue(st);
        while (!q.isEmpty()) {
            int tmp = q.deQueue();
            for (int k = 0; k < numVer; k++) {
                // investigate adjMatrix[tmp][k]
                if (adjMatrix[tmp][k] == 0) continue;
                if (visited[k]) continue;
                visited[k] = true;
                cout << verList.getEleAtPos(k) << " ";
                q.enQueue(k);
            }
        }
    }

    void DFShelper(int st, bool* visited) {
        visited[st] = true;
        cout << verList.getEleAtPos(st) << " ";
        for (int k = 0; k < numVer; k++) {
            if (adjMatrix[st][k] == 0) continue;
            if (visited[k]) continue;
            DFShelper(k, visited);
        }
    }

    AMGraph() { // we don't want this used.
    }
    AMGraph(VecList<T>nodes, int n, bool dir = false) {
        // n for number of vertices
        // default for undirected graph
        // edges to be added later.

        numVer = n;
        numEdge = 0;
        for (int i = 0; i < n; i++) {
            verList.insertLast(nodes.getEleAtPos(i));
        }
        directed = dir;
        adjMatrix = new int* [n];
        originaladjMatrix = new int* [n];
        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new int[n];
            originaladjMatrix[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                adjMatrix[i][j] = 0;
                originaladjMatrix[i][j] = 0;
            }
            
        }
    }
    AMGraph(T* arr, int n, Edge<T>** eArr, int e, bool dir = false) {
        // n for number of vertices
        // default for undirected graph
        // edges to be added now.

        numVer = n;
        numEdge = 0;
        for (int i = 0; i < n; i++) {
            verList.insertLast(arr[i]);
        }
        directed = dir;
        cout << "图的节点如下：" << endl;
        for (int i = 0; i < n; i++) 
        {
            cout << verList.getEleAtPos(i) << endl;
        }
        adjMatrix = new int* [n];
        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new int[n];
            for (int j = 0; j < n; j++)
                adjMatrix[i][j] = 0;
        }

        for (int i = 0; i < e; i++) {
            addEdge(eArr[i]->start, eArr[i]->end, eArr[i]->weight);
        }
    }
    ~AMGraph() {
        for (int i = 0; i < numVer; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
    void printnodes()
    {
        for (int i = 0; i < numVer; i++) {
            cout << verList.getEleAtPos(i);
        }
    }
    void addEdge(Edge<T> e) {
        addEdge(e.start, e.end, e.weight);
    }
    void addEdge(T st, T en, int weight) {
        int sIndex = verList.locateEle(st);
        int eIndex = verList.locateEle(en);
        if (sIndex == -1 || eIndex == -1)cout << "Wrong Input!" << endl;
        if (adjMatrix[sIndex][eIndex] == 0)
        {
            numEdge++;
        }
        if (originaladjMatrix[sIndex][eIndex] == 0)
        {
            originaladjMatrix[sIndex][eIndex] = weight;
            originaladjMatrix[eIndex][sIndex] = weight;
        }
        adjMatrix[sIndex][eIndex] = weight;
        if (!directed) adjMatrix[eIndex][sIndex] = weight;
    }
    void removeEdge(Edge<T> e) {
        removeEdge(e.start, e.end);
    }
    int getOriginalWeight(T st, T en) {
        int sIndex = verList.locateEle(st);
        int eIndex = verList.locateEle(en);
        return  originaladjMatrix[sIndex][eIndex];
    }
    void removeEdge(T st, T en) {
        int sIndex = verList.locateEle(st);
        int eIndex = verList.locateEle(en);
        if (adjMatrix[sIndex][eIndex] == 0) return;
        numEdge--;
        adjMatrix[sIndex][eIndex] = 0;
        if (!directed) adjMatrix[eIndex][sIndex] = 0;
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

    pair<VecList<T>, int> DijkstraTotwopoint(T st, T ed, bool* if_ban, int newlimit,VecList<T>Rootpath)
    { // positive weights

        bool* isInS = new bool[numVer];
        int* dist = new int[numVer];
        int* lastNode = new int[numVer];
        int* intermediates = new int[numVer];
        int limit = -1;
        if (newlimit != -1)limit = newlimit - Rootpath.getLength()+2;
        // 初始化
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

            return pair<VecList<T>, int>(VecList<T>(), INT_MAX);
        }
        isInS[sIndex] = true;
        dist[sIndex] = 0;
        for (int i = 0; i < Rootpath.getLength(); i++)
        {
            int index = verList.locateEle(Rootpath.getEleAtPos(i));
            isInS[index] = true;
         }
        for (int i = 0; i < numVer; i++) {
            if (if_ban[i]) continue;
            if (adjMatrix[sIndex][i] == 0) continue;
            dist[i] = adjMatrix[sIndex][i];
            lastNode[i] = sIndex;
            intermediates[i] = 1; // 起点到相邻节点有1个中继点（起点不算） 
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
            if (tmpIndex == -1) {
                break;
            }

            // 将最短路径节点加入集合S
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
            int count = 0; // 添加计数器以防止无限循环

            // 使用一个数组或列表来记录已访问的节点
            bool* visitedPath = new bool[numVer];
            for (int i = 0; i < numVer; i++) visitedPath[i] = false;

            while (j != -1 && count < numVer) {
                if (j < 0 || j >= numVer) {
                    cout << "Error: Invalid index " << j << " while constructing path." << endl;
                    break;
                }
                // 检查节点是否已在路径中
                if (visitedPath[j]) {
                    cout << "Detected a duplicate vertex in the path. Aborting path construction." << endl;
                    path.clear();
                    totalDist = INT_MAX;
                    break;
                }
                S.push(j);
                visitedPath[j] = true; // 标记为已访问
                j = lastNode[j];
                count++;
            }
            delete[] visitedPath;

            if (count < numVer) { // 确保没有检测到重复顶点
                // 构建路径
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
        return pair<VecList<T>, int>(path, totalDist);
    }

    int getweight(T a, T b)
    {
        int index1 = verList.locateEle(a);
        int index2 = verList.locateEle(b);
        return adjMatrix[index1][index2];
    }
    int getposInver(T x)
    {
        return verList.locateEle(x);
    }

};
void printMartix(int m, int** arr)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}
//KSP算法

template <class T>
class Solution {
public:
    AMGraph<T>G;
    bool* if_ban;
    int limit;
    VecList<VecList<T>>paths;
    VecList<int>totalweights;
    int nodesnum;
    VecList<T>nodes;
    int edgesnum;
  
    Solution() {

    }
    Solution(int m, int n, VecList<T> strings, vector<Edge<T>> edges)
        : G(strings, m) // 初始化 AMGraph 对象
    {
        nodesnum = m;
        edgesnum = n;
        if_ban = new bool[nodesnum];
        for (int i = 0; i < nodesnum; i++) {
            if_ban[i] = false;
        }
        limit = -1;

      //  cout << "图成功构建,节点如下：" << endl;
      //  G.printnodes();

        for (int i = 0; i < m; i++) {
            nodes.insertLast(strings.getEleAtPos(i));
            if_ban[i] = false;
        }
        for (int i = 0; i < n; i++) {
           // cout << "插入边：" << edges[i].start << "->" << edges[i].end << endl;
            G.addEdge(edges[i]);
        }
      //  cout << "Solution established!" << endl;
    }

    ~Solution() {
        delete[] if_ban;
    }
  
    bool if_In(VecList<T> path) {
        bool if_In = false;
        for (int i = 0; i < paths.getLength(); i++)
        {
            if (paths.getEleAtPos(i)==path)
            {
                if_In = true;
                break;
            }
        }
        return if_In;
    }

    int getpathweight(VecList<T> path)
    {
        int pathweight = 0;
        for (int i = 0; i < path.getLength() - 1; i++) {
            int w = G.getweight(path.getEleAtPos(i), path.getEleAtPos(i + 1));
            if (w == INT_MAX) {
                // 如果有不可达的边，返回一个很大的值
                return INT_MAX;
            }
            // 检查是否会溢出
            if (pathweight > INT_MAX - w) {
                return INT_MAX;
            }
            pathweight += w;
        }
        return pathweight;
    }

    vector<int> pathToIndices(VecList<T> path) {
        vector<int> indices;
        for (int i = 0; i < path.getLength(); i++) {
            int idx = G.getposInver(path.getEleAtPos(i));
            if (idx == -1) {
                cout << "Warning: Node " << path.getEleAtPos(i) << " not found in verList" << endl;
                return vector<int>(); // 返回空向量
            }
            indices.push_back(idx);
        }
        return indices;
    }

    VecList<T> indicesToPath(const vector<int>& indices) {
        VecList<T> path;
        VecList<T> visited; // 用于记录已访问的顶点

        for (size_t i = 0; i < indices.size(); i++) {
            T node = G.verList.getEleAtPos(indices[i]);

            // 检查节点是否已存在于路径中
            if (visited.contains(node)) { 
                path.clear();
                return path;
            }

            path.insertLast(node);
            visited.insertLast(node);
        }
        return path;
    }

    int getminpath(VecList<VecList<T>> pathsTopick)
    {
        if (pathsTopick.isEmpty()) return -1; // 增加空路径检查
        int minweight = getpathweight(pathsTopick.getEleAtPos(0));
        int pos = 0;
        for (int i = 1; i < pathsTopick.getLength(); i++)
        {
            int currentWeight = getpathweight(pathsTopick.getEleAtPos(i));
            if (currentWeight < minweight)
            {
                minweight = currentWeight;
                pos = i;
            }
        }
        return pos;
    }
    int getminpathweight(VecList<VecList<T>> pathsTopick)
    {
        if (pathsTopick.isEmpty()) return -1; // 增加空路径检查
        int minweight = getpathweight(pathsTopick.getEleAtPos(0));
        int pos = 0;
        for (int i = 1; i < pathsTopick.getLength(); i++)
        {
            int currentWeight = getpathweight(pathsTopick.getEleAtPos(i));
            if (currentWeight < minweight)
            {
                minweight = currentWeight;
                pos = i;
            }
        }
        return pos;
    }
    VecList<pair<int,int>>PosInPaths(T x)
    {
        VecList<pair<int,int>>posinpaths;
        for (int i = 0; i < paths.getLength(); i++)
        {
            int pos = paths.getEleAtPos(i).locateEle(x);
            if (pos != -1)
            {
                pair<int, int>p(pos, i);
                posinpaths.insertLast(p);
            }
        }
        return posinpaths;
    }
    void addpath(VecList<T>path, int weight) {
        if (if_In(path) || path.isEmpty()||weight==INT_MAX) return; 
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
    

        // Step 1: 找到第一条最短路径
      pair<VecList<T>, int> firstPathPair = G.DijkstraTotwopoint(start, end, if_ban, limit,VecList<T>());
        if (firstPathPair.second == INT_MAX) {
           cout << "没有找到从 " << start << " 到 " << end << " 的路径。" << endl;
            return;
        }
        VecList<T> firstPath = firstPathPair.first;
        int firstWeight = firstPathPair.second;
        addpath(firstPath, firstWeight);
        auto comparator = [](const pair<VecList<T>, int>& a, const pair<VecList<T>, int>& b) {
            return a.second > b.second;
            };
       priority_queue<pair<VecList<T>, int>, vector<pair<VecList<T>, int>>, decltype(comparator)> B(comparator);

        // A_paths 存储已找到的路径
        VecList<VecList<T>> A_paths;
        A_paths.insertLast(firstPath);
        // Step 2: 迭代寻找 K-1 条路径
        for (int k = 1; k < K; ++k) {
                // 生成 spur 路径
                VecList<VecList<T>>pathsbepicked;
                VecList<T> currentPath = A_paths.getEleAtPos(A_paths.getLength()-1);
                int pathLen = currentPath.getLength();
                   for (int j = 0; j < pathLen-1; ++j) {
                    // Spur 节点
                    T spurNode = currentPath.getEleAtPos(j);
                    // Root 路径
                    VecList<T> rootPath;
                    for (int m = 0; m <= j; ++m) {
                        rootPath.insertLast(currentPath.getEleAtPos(m));
                    }
                    // 暂时移除会导致重复路径的边
                      vector<pair<T, T>> removedEdges;
                    for (int p = 0; p < paths.getLength(); ++p) {
                        VecList<T> existingPath = paths.getEleAtPos(p);
                        bool sharePrefix = true;//是否共享相同的前缀
                        for (int m = 0; m <= j; ++m) {
                            if (existingPath.getEleAtPos(m) != rootPath.getEleAtPos(m)) {
                                sharePrefix = false;
                                break;
                            }
                        }
                        //这里是检查出来到spur点之前的路径都相同
                        if (sharePrefix && existingPath.getLength() > j + 1) {
                            T edgeEnd = existingPath.getEleAtPos(j + 1);
                            G.removeEdge(spurNode, edgeEnd);
                          //  cout << spurNode << "->" << edgeEnd << "被移除" << endl;
                            removedEdges.emplace_back(make_pair(spurNode, edgeEnd));
                        }
                    }

                    // 查找 Spur 路径
                    pair<VecList<T>, int> spurPathPair = G.DijkstraTotwopoint(spurNode, end, if_ban, limit, rootPath);
                    //从supurNode到end的最短路径
                    if (spurPathPair.second != INT_MAX) {
                        VecList<T> spurPath = spurPathPair.first;
                        // 合并 Root 和 Spur 路径
                        cout << "spur路径为：";
                        for (int i = 0; i < spurPath.getLength(); i++)
                        {
                            cout << spurPath.getEleAtPos(i);
                            if (i != spurPath.getLength() - 1) cout << "->";
                        }
                        cout << endl;
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

                            // 添加到候选堆
                            if (!if_In(totalPath)) {
                                pathsbepicked.insertLast(totalPath);
                                B.push(make_pair(totalPath, totalWeight));
                              //  cout << "得到候选路径：" << endl;
                             //   for (int j = 0; j < totalPath.getLength(); j++)
                                //{
                                //    cout << totalPath.getEleAtPos(j);
                              //      if (j != totalPath.getLength() - 1)cout << "->";
                             //   }
                             //   cout << endl;
                             //   cout << "候选路径已添加到堆中，权重：" << totalWeight << endl;
                            }
                          //  else { cout << "路径重复" << endl; }
                        }
                      //  else { cout << "路径不存在" << endl; }
                    }
                   // else {
                   //   cout <<"从 "<<spurNode<<"到"<<end << "无环路径不存在" << endl;
                  //  }
                    // 恢复移除的边
                    for (int edge = 0; edge < removedEdges.size();edge++)
                    {
                        int weight = G.getOriginalWeight(removedEdges[edge].first, removedEdges[edge].second);
                        G.addEdge(removedEdges[edge].first, removedEdges[edge].second, weight);
                       // cout << removedEdges[edge].first << "->" << removedEdges[edge].second<< "被恢复" << endl;
                    }
                }
            

            bool found = false;
            while (!B.empty()) {
               // cout << "所有候选路径如下：" << endl;
               // for (int i = 0; i < pathsbepicked.getLength(); i++)
              //  {
               //     for (int j = 0; j < pathsbepicked.getEleAtPos(i).getLength(); j++)
               //     {
                 //       cout << pathsbepicked.getEleAtPos(i).getEleAtPos(j);
                 //       if (j != pathsbepicked.getEleAtPos(i).getLength() - 1)cout << "->";
                 //   }
               //     cout <<"权重："<<getpathweight(pathsbepicked.getEleAtPos(i))<<   endl;
             //   }
               pair<VecList<T>, int> candidate = B.top();
                B.pop();
                if (!if_In(candidate.first)) {
                    addpath(candidate.first, candidate.second);
                    A_paths.insertLast(candidate.first);
                   cout << "选择路径 " << (k + 1) << "，权重：" << candidate.second << std::endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
              // cout << "现在的矩阵为："<<endl;
               printMartix(G.numVer,G.adjMatrix);
                break;
            }
        }

        // 输出结果
      cout << "找到 " << paths.getLength() << " 条路径：" << std::endl;
        for (int i = 0; i < paths.getLength(); ++i) {
            cout << "路径 " << (i + 1) << ": ";
            for (int j = 0; j < paths.getEleAtPos(i).getLength(); ++j) {
                cout << paths.getEleAtPos(i).getEleAtPos(j);
                if (j != paths.getEleAtPos(i).getLength() - 1)
                    cout << "->";
            }
           cout << ", 总权重 = " << totalweights.getEleAtPos(i) << std::endl;
        }
    }
};

int main() {
    int m=0, n = 0;
    cin >> m >> n;
    if (m < 0 || n < 0)
    {
        cout << "顶点和边数必须为非负整数" << endl;
        return 0;
    }
   VecList<char>strings;
    VecList<char>S1;
    VecList<char>S2;
    VecList<int>weight;
    for (int i = 0; i < m; i++)
    {
        char string;
        cin >> string;
        strings.insertLast(string);
    }
    cout << "读取到的节点：";
    for (int i = 0; i < m; i++)
    {
        cout<<strings.getEleAtPos(i)<<endl;
    }
    vector<Edge<char>>edges;
   for(int i=0;i<n;i++)
    {
        char s1;
        char s2;
        int w;
        cin >> s1 >> s2 >> w;
        S1.insertLast(s1);
        S2.insertLast(s2);
        weight.insertLast(w);
        Edge<char>edge;
        edge.start = s1;
        edge.end = s2;
        edge.weight = w;
        edges.push_back(edge);
       if (!strings.contains(s1)|| !strings.contains(s2))
       {
          cout << "输入了错误字串" << endl;
        }
        cout << "读取到的边为" << s1 <<"->"<< s2 <<"权重：" << w << endl;
    }
  // cout << "well Input" << endl;
   string command;
    Solution<char> A(m, n,strings,edges);
    int** arr = A.G.getMatrix();
    printMartix(m,arr);
    while (cin >> command)
    {
       
            if (command == "ban") {
                char s;
                cin >> s;
                int pos = A.nodes.locateEle(s);
                if (pos == -1)cout << "节点不存在" << endl;
                A.if_ban[pos] = true;
            }
        
            else if (command == "unban") {
                char s;
                cin >> s;
                int pos = A.nodes.locateEle(s);
                if (pos == -1)cout << "节点不存在" << endl;
                A.if_ban[pos] = false;
            }
        
            else if (command == "maxTrans") {
                int Y;
                cin >> Y;
                if (Y >= 0)A.limit = Y;
                else A.limit = -1;
            }
            else if (command == "paths")
            {
                char start;
                char end;
                int k;
                cin >> start;
                cin >> end;
                cin >> k;
                A.minpaths(start, end, k);
            }
            else if (command == "quit") {
                return 0;
            }
            else { cout << "未知指令：" << command << endl; }
        
    }
    
    return 0;
}