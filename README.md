# CppProgramFiles

我的所有 C++ 相关项目文件

## 目录及简介

- [算法基础课](Basic) &#x2002;
  内容全部来自[`算法基础课`](https://www.acwing.com/activity/content/11/)
    - [基础算法](Basic/BasicAlgorithms) &#x2002;
      包括排序、二分、高精度、前缀和与差分、双指针算法、位运算、离散化、区间合并等内容。
    - [数据结构](Basic/DataStructure) &#x2002;
      包括单链表，双链表，栈，队列，单调栈，单调队列，KMP，Trie，并查集，堆，哈希表等内容。
        - [单链表](Basic/DataStructure/SingleList.cpp)
        - [`双链表`](https://www.acwing.com/activity/content/problem/content/864/) &#x2002; 太懒了，嫌麻烦没写
        - [栈](Basic/DataStructure/Stack)
            - [模拟栈](Basic/DataStructure/Stack/SimulationStack.cpp)
            - [栈的应用：表达式求值](Basic/DataStructure/Stack/ExpressionEvaluation.cpp)
        - [队列](Basic/DataStructure/Queue.cpp)
        - [单调栈](Basic/DataStructure/MonotonicStack.cpp)
        - [单调队列](Basic/DataStructure/MonotonicQueue.cpp)
        - [KMP字符串](Basic/DataStructure/KMP.cpp)
        - [Trie](Basic/DataStructure/Tire)
            - [Trie字符串统计](Basic/DataStructure/Tire/StringStatistics.cpp)
            - [最大异或对](Basic/DataStructure/Tire/MaximumXorPair.cpp)
        - [并查集](Basic/DataStructure/AndLookup)
            - [合并集合](Basic/DataStructure/AndLookup/MergeCollection.cpp)
            - [连通块中点的数量](Basic/DataStructure/AndLookup/ConnectedBlockPointNum.cpp)
            - [食物链](Basic/DataStructure/AndLookup/FoodChain.cpp)
        - [堆](Basic/DataStructure/Heap)
            - [堆排序](Basic/DataStructure/Heap/HeapSort.cpp)
            - [模拟堆](Basic/DataStructure/Heap/MockHeap.cpp)
        - [哈希表](Basic/DataStructure/Hash)
            - [模拟散列表](Basic/DataStructure/Hash/AnalogHash.cpp)
            - [字符串哈希](Basic/DataStructure/Hash/StringHash.cpp)
    - [搜索与图论](Basic/SearchAndGraphTheory) &#x2002;
      包括DFS，BFS，树与图的深度优先遍历，树与图的广度优先遍历，拓扑排序，Dijkstra，bellman-ford，spfa，Floyd，Prim，Kruskal，染色法判定二分图，匈牙利算法等内容。
        - [DFS](Basic/SearchAndGraphTheory/DFS)
            - [排列数字](Basic/SearchAndGraphTheory/DFS/ArrangeNumbers.cpp)
            - [n-皇后问题](Basic/SearchAndGraphTheory/DFS/NQueens.cpp)
        - [BFS](Basic/SearchAndGraphTheory/BFS)
            - [走迷宫](Basic/SearchAndGraphTheory/BFS/MazeWalking.cpp)
            - [`八数码`](https://www.acwing.com/problem/content/847/) &#x2002; 太麻烦了，这个就不写了吧
        - [树与图的深度优先遍历](Basic/SearchAndGraphTheory/DFS/DFS.cpp)
        - [树与图的广度优先遍历](Basic/SearchAndGraphTheory/BFS/BFS.cpp)
        - [拓扑排序](Basic/SearchAndGraphTheory/TopologicalSort.cpp)
        - [Dijkstra](Basic/SearchAndGraphTheory/Dijkstra)
            - [Dijkstra求最短路I](Basic/SearchAndGraphTheory/Dijkstra/DijkstraI.cpp)
            - [Dijkstra求最短路II](Basic/SearchAndGraphTheory/Dijkstra/DijkstraII.cpp)
        - [bellman ford](Basic/SearchAndGraphTheory/BellmanFord.cpp)
        - [spfa](Basic/SearchAndGraphTheory/SPFA)
            - [spfa求最短路](Basic/SearchAndGraphTheory/SPFA/FindShortestPath.cpp)
            - [spfa判断负环](Basic/SearchAndGraphTheory/SPFA/JudgmentNegativeLoop.cpp)
        - [Floyd](Basic/SearchAndGraphTheory/Floyd.cpp)
- [其他题解](OtherSolutions) &#x2002; 非系统性学习的题目
    - [左孩子右兄弟](OtherSolutions/LeftChildRightBrother.cpp)