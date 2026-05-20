# Graph Algorithms and K-Shortest Paths in C++

课程属性：数据结构与算法课程项目 2  
原始材料：`raw/大作业2.cpp`, `raw/proj2_23339050_20241224145819.pdf`

## 项目目标

本项目使用 C++ 实现图结构与路径搜索算法，在自定义数据结构基础上完成无向带权图的构建、Dijkstra 两点最短路径搜索，以及带约束的 K 条最短路径搜索。

## 文件结构

```text
projects/dsa-k-shortest-paths/
  include/
    VecList.hpp
    LinkStack.hpp
    LinkQueue.hpp
    Graph.hpp
    KShortestPaths.hpp
  src/
    main.cpp
  README.md
  CHANGES.md
```

## 数据结构设计

- `VecList<T>`: 顺序表，支持插入、删除、查找、复制赋值和路径相等比较。
- `LinkStack<T>`: 链式栈，用于 Dijkstra 回溯路径。
- `LinkQueue<T>`: 链式队列，用于 BFS 辅助遍历。
- `AMGraph<T>`: 邻接矩阵图结构，保存当前权重矩阵与原始权重矩阵，支持临时删边与恢复。
- `Solution<T>`: 封装 KSP 求解状态，包括黑名单、最大中继限制、路径集合和权重集合。

## 算法流程

### DijkstraTotwopoint

1. 初始化距离数组、前驱数组和中继点计数数组。
2. 若起点、终点被加入黑名单，则返回不可达。
3. 在常规 Dijkstra 基础上加入两个约束：
   - 不经过被 ban 的中继点。
   - 中继点数量不超过 `maxTrans`。
4. 使用栈回溯前驱数组，构造从起点到终点的路径。

### K Shortest Paths

该部分参考 Yen's Algorithm 的 root/spur 思路：

1. 先用 Dijkstra 找到第一条最短路径。
2. 对上一条已选路径中的每个 spur node，取其前缀作为 root path。
3. 临时删除与已有路径共享 root path 后会导致重复的边。
4. 从 spur node 到终点重新运行 Dijkstra，得到 spur path。
5. 合并 root path 与 spur path，加入候选优先队列。
6. 恢复被临时删除的边。
7. 从候选队列中选择权重最小且未出现过的路径，直到得到 K 条路径或无候选路径。

## 编译运行

```bash
g++ -std=c++17 src/main.cpp -Iinclude -o ksp
./ksp
```

Windows PowerShell 示例：

```powershell
g++ -std=c++17 .\src\main.cpp -I.\include -o ksp.exe
.\ksp.exe
```

## 输入输出示例

输入：

```text
5 7
A B C D E
A B 1
A C 2
B C 1
B D 4
C D 1
C E 5
D E 1
paths A E 3
quit
```

输出示例：

```text
选择路径 2，权重：4
选择路径 3，权重：6
找到 3 条路径：
路径 1: A->C->D->E, 总权重 = 4
路径 2: A->B->C->D->E, 总权重 = 4
路径 3: A->C->E, 总权重 = 7
```

说明：当存在同权重路径时，输出顺序可能受候选队列插入顺序影响。

## 支持命令

- `ban X`: 将节点 `X` 加入中继点黑名单。
- `unban X`: 解除节点 `X` 的黑名单状态。
- `maxTrans Y`: 设置最大中继点数量，负数表示不限制。
- `paths S T K`: 查询从 `S` 到 `T` 的 K 条最短路径。
- `quit`: 退出程序。

## 复杂度分析

- 邻接矩阵版 Dijkstra 单次复杂度约为 `O(V^2)`。
- Yen-style KSP 中，每次选路会对路径上的 spur node 多次运行 Dijkstra。粗略估计为 `O(K * V * V^2)`，实际还受到路径长度、候选队列大小和删边恢复次数影响。
- 空间复杂度主要来自邻接矩阵 `O(V^2)`、候选路径集合与路径存储。

## 课程收获

这个项目把基础数据结构与图算法联系在一起。实现过程中，难点不只在 Dijkstra 本身，也包括路径去重、边的临时删除与恢复、黑名单约束、中继点数量限制，以及候选路径的优先级管理。

## 说明

整理版保留原始项目的课程作业属性和核心算法思路。代码做了文件拆分、头文件保护和少量编译友好的接口调整，没有将其包装为工业级路径规划系统。
