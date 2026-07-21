/*
Problem: Rotting Oranges
Platform: LeetCode
Pattern: Graphs (Multi-Source BFS)
Folder: 17_Graphs
Difficulty: Medium

Problem Statement:
You are given an m x n grid where:
- 0 represents an empty cell
- 1 represents a fresh orange
- 2 represents a rotten orange

Every minute, any fresh orange adjacent
(up, down, left, right) to a rotten orange
becomes rotten.

Return the minimum number of minutes required
to rot all oranges.
If impossible, return -1.

Approach:
1. Push all initially rotten oranges into a queue.
2. Perform Multi-Source BFS.
3. Each BFS level represents one minute.
4. Spread rot to all adjacent fresh oranges.
5. After BFS, check if any fresh orange remains.

Time Complexity: O(m × n)
Space Complexity: O(m × n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<pair<pair<int,int>, int>> q;

        // Push all initially rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        int ans = 0;

        while(!q.empty()) {

            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;

            q.pop();

            ans = max(ans, time);

            // Up
            if(i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1) {
                q.push({{i - 1, j}, time + 1});
                vis[i - 1][j] = true;
            }

            // Down
            if(i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1) {
                q.push({{i + 1, j}, time + 1});
                vis[i + 1][j] = true;
            }

            // Left
            if(j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1) {
                q.push({{i, j - 1}, time + 1});
                vis[i][j - 1] = true;
            }

            // Right
            if(j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1) {
                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = true;
            }
        }

        // Check for any remaining fresh orange
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};

/*
Key Learning:
1. Multi-Source BFS starts from multiple sources simultaneously.
2. Queue stores {cell, time}.
3. Each BFS level represents one minute.
4. Standard shortest-time spread simulation problem.
*/
