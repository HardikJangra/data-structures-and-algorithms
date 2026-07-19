/*
Problem: The K Weakest Rows in a Matrix
Platform: LeetCode
Pattern: Heap (Max Heap)
Folder: 18_Heap
Difficulty: Easy

Problem Statement:
You are given an m x n binary matrix mat where:
- 1 represents a soldier
- 0 represents a civilian

The soldiers are always positioned before civilians in each row.

Return the indices of the k weakest rows in the matrix.

A row is weaker if:
1. It has fewer soldiers.
2. If soldiers are equal, the row with the smaller index is weaker.

Approach:
1. Count soldiers in every row.
2. Store {soldiers, rowIndex} in a Max Heap.
3. Keep heap size equal to k.
4. Remove the strongest row whenever heap size exceeds k.
5. Extract remaining row indices.
6. Reverse the answer because Max Heap returns strongest first.

Time Complexity: O(m × n + m log k)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < mat.size(); i++) {

            int soldiers = 0;

            for(int j = 0; j < mat[0].size(); j++) {

                if(mat[i][j] == 1)
                    soldiers++;
            }

            pq.push({soldiers, i});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*
Key Learning:
1. Heap stores {soldierCount, rowIndex}.
2. Max Heap keeps only the k weakest rows.
3. Pair comparison automatically handles tie-breaking.
4. Reverse the final answer because extraction order is strongest to weakest.
*/
