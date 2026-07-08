/*
Problem: Island Perimeter
Platform: LeetCode
Pattern: Graphs (DFS)
Folder: 17_Graphs
Difficulty: Easy

Problem Statement:
You are given a grid where:
- 1 represents land
- 0 represents water

The grid contains exactly one island.

Return the perimeter of the island.

Approach:
1. Find the first land cell.
2. Perform DFS.
3. For every DFS call:
   - If we go outside the grid or reach water,
     increment perimeter.
   - If cell is already visited, return.
4. Mark visited land as -1.

Time Complexity: O(m × n)
Space Complexity: O(m × n)
(Recursion stack in worst case)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int perimeter;

    void dfs(vector<vector<int>>& grid, int i, int j) {

        // Water or boundary contributes to perimeter
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            perimeter++;
            return;
        }

        // Already visited
        if(grid[i][j] == -1) {
            return;
        }

        // Mark visited
        grid[i][j] = -1;

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        perimeter = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }

        return 0;
    }
};

/*
Key Learning:
1. DFS explores every land cell exactly once.
2. Every water cell or grid boundary adjacent to land
   contributes one unit to the perimeter.
3. Mark visited cells to avoid revisiting.
4. Classic grid DFS problem.
*/
