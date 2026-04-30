/*
Problem: Interval List Intersections
Platform: LeetCode
Pattern: Two Pointers + Intervals
Folder: 10_Greedy_Intervals
Difficulty: Medium

Problem Statement:
You are given two lists of closed intervals, each list is pairwise disjoint
and sorted in ascending order.

Return the intersection of these two interval lists.

Approach:
1. Use two pointers for both lists.
2. For each pair of intervals:
   - Find overlap:
     start = max(start1, start2)
     end = min(end1, end2)
   - If start <= end → valid intersection.
3. Move the pointer with smaller end

Time Complexity: O(n + m)
Space Complexity: O(1) (excluding result)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int m = b.size();

        vector<vector<int>> res;

        int i = 0, j = 0;

        while(i < n && j < m) {
            int start1 = a[i][0];
            int end1 = a[i][1];

            int start2 = b[j][0];
            int end2 = b[j][1];

            int start = max(start1, start2);
            int end = min(end1, end2);

            if(start <= end) {
                res.push_back({start, end});
            }

            if(end1 < end2) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};

/*
Key Learning:
1. Always use max(start), min(end) for overlap.
2. Move pointer with smaller ending interval.
3. Classic two-pointer interval problem.
4. Much cleaner than multiple if-else checks.
*/
