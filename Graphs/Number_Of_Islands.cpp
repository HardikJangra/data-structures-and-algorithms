/*
Problem: Number of Islands
Platform: LeetCode
Pattern: Graphs (DFS on Grid)
Folder: 17_Graphs
Difficulty: Medium

Problem Statement:
Given an m x n grid of '1's (land) and '0's (water),
return the number of islands.

An island is surrounded by water and is formed by
connecting adjacent lands horizontally or vertically.

Approach:
1. Traverse every cell in the grid.
2. Whenever an unvisited land cell ('1') is found:
   - Start DFS.
   - Mark all connected land cells as visited.
   - Increment island count.
3. Continue until the entire grid is processed.

Time Complexity: O(m × n)
Space Complexity: O(m × n)
(Recursion stack in worst case)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int island = 0;

    vector<pair<int,int>> dir = {
        {1,0},
        {-1,0},
        {0,-1},
        {0,1}
    };

    void dfs(vector<vector<char>>& grid, int i, int j) {

        if(i < 0 || i >= grid.size() ||
           j < 0 || j >= grid[0].size() ||
           grid[i][j] != '1') {
            return;
        }

        // Mark visited
        grid[i][j] = '$';

        for(auto &p : dir) {
            int newRow = i + p.first;
            int newCol = j + p.second;

            dfs(grid, newRow, newCol);
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    island++;
                }
            }
        }

        return island;
    }
};

/*
Key Learning:
1. DFS explores an entire connected component.
2. One DFS call corresponds to one island.
3. Mark visited cells to avoid revisiting.
4. Fundamental grid graph traversal problem.
*/
