/*
Problem: Adjacency List Representation
Platform: GeeksforGeeks
Pattern: Graph Representation
Folder: 17_Graphs
Difficulty: Easy

Problem Statement:
Given the number of vertices V and a list of edges,
construct and return the adjacency list representation
of an undirected graph.

Approach:
1. Create an adjacency list of size V.
2. Traverse every edge (u, v).
3. Since the graph is undirected:
   - Add v to u's adjacency list.
   - Add u to v's adjacency list.
4. Return the adjacency list.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {

        vector<vector<int>> adj(V);

        for(auto &edge : edges) {

            int u = edge.first;
            int v = edge.second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
};

/*
Key Learning:
1. Adjacency list is the most common graph representation.
2. Space efficient for sparse graphs.
3. For an undirected graph, every edge is stored twice.
4. Foundation for DFS, BFS, and shortest path algorithms.
*/
