/*
Problem: BFS of Graph
Platform: GeeksforGeeks
Pattern: Graph Traversal (BFS)
Folder: 17_Graphs
Difficulty: Easy

Problem Statement:
Given a connected undirected graph represented as an
adjacency list, perform Breadth First Search (BFS)
starting from vertex 0.

Return the BFS traversal.

Approach:
1. Create a visited array.
2. Push the starting node (0) into the queue.
3. Mark it as visited.
4. While the queue is not empty:
   - Remove the front node.
   - Add it to the answer.
   - Push all unvisited neighbors into the queue.
5. Continue until the queue becomes empty.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {

        int n = adj.size();

        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> result;

        q.push(0);
        visited[0] = true;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            result.push_back(node);

            for(int i = 0; i < adj[node].size(); i++) {

                int neigh = adj[node][i];

                if(!visited[neigh]) {
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }

        return result;
    }
};

/*
Key Learning:
1. BFS explores level by level.
2. Queue maintains the traversal order.
3. Mark nodes visited before pushing into queue.
4. Fundamental algorithm for shortest path in unweighted graphs.
*/
