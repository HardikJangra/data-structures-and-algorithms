/*
Problem: Find K Closest Elements
Platform: LeetCode
Pattern: Heap (Max Heap)
Folder: 18_Heap
Difficulty: Medium

Problem Statement:
Given a sorted array arr, two integers k and x,
return the k closest integers to x in the array.

The result should also be sorted in ascending order.

Approach:
1. Maintain a Max Heap storing:
   {distance from x, value}
2. For every element:
   - Compute abs(num - x).
   - Push {distance, value} into heap.
3. If heap size exceeds k:
   - Remove the farthest element.
4. Extract remaining elements.
5. Sort the answer before returning.

Time Complexity: O(n log k + k log k)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<pair<int,int>> pq;

        for(int num : arr) {

            pq.push({abs(num - x), num});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

/*
Key Learning:
1. Priority is based on distance from x.
2. Use a Max Heap to keep only the k closest elements.
3. Heap stores {distance, value}.
4. Sort the final answer because the required output
   must be in ascending order.
*/
