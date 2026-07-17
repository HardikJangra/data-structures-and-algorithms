/*
Problem: DFS of Graph
Platform: GeeksforGeeks
Pattern: Graph Traversal (DFS)
Folder: 17_Graphs
Difficulty: Easy

Problem Statement:
Given a connected undirected graph represented as an
adjacency list, perform Depth First Search (DFS)
starting from vertex 0.

Return the DFS traversal.

Approach:
1. Create a visited array.
2. Start DFS from node 0.
3. Mark current node as visited.
4. Add current node to the answer.
5. Recursively visit all unvisited neighbors.

Time Complexity: O(V + E)
Space Complexity: O(V)
(Visited array + recursion stack)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void df(vector<vector<int>>& adj,
            int node,
            vector<int>& result,
            vector<bool>& visited)
    {
        result.push_back(node);
        visited[node] = true;

        for(int i = 0; i < adj[node].size(); i++) {

            int neigh = adj[node][i];

            if(!visited[neigh]) {
                df(adj, neigh, result, visited);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {

        int n = adj.size();

        vector<int> result;
        vector<bool> visited(n, false);

        df(adj, 0, result, visited);

        return result;
    }
};

/*
Key Learning:
1. DFS explores one complete path before backtracking.
2. Always mark a node as visited before exploring neighbors.
3. Recursion naturally implements DFS.
4. Fundamental graph traversal algorithm.
*/
