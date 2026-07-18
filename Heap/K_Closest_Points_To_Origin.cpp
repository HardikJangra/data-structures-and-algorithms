/*
Problem: K Closest Points to Origin
Platform: LeetCode
Pattern: Heap (Max Heap)
Folder: 18_Heap
Difficulty: Medium

Problem Statement:
Given an array of points where points[i] = [xi, yi]
represents a point on the X-Y plane and an integer k,
return the k closest points to the origin (0, 0).

The distance between two points is:
√(x² + y²)

You may return the answer in any order.

Approach:
1. Compute squared distance:
   x² + y²
   (No need to calculate square root.)
2. Maintain a Max Heap of size k:
   {distance, point}
3. If heap size exceeds k:
   - Remove the farthest point.
4. Remaining points are the k closest.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>> pq;

        for(auto &point : points) {

            int x = point[0];
            int y = point[1];

            int dist = x * x + y * y;

            pq.push({dist, point});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {

            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

/*
Key Learning:
1. Compare squared distances instead of actual distances.
2. Square root is unnecessary because ordering remains unchanged.
3. Use a Max Heap to keep only the k closest points.
4. Classic Top-K heap problem.
*/
