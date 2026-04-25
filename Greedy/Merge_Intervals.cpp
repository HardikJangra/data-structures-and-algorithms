/*
Problem: Merge Intervals
Platform: LeetCode
Pattern: Greedy + Sorting (Intervals)
Folder: 10_Greedy
Difficulty: Medium

Problem Statement:
Given an array of intervals where intervals[i] = [start, end],
merge all overlapping intervals and return an array of non-overlapping intervals.

Approach:
1. Sort intervals based on start time.
2. Initialize first interval.
3. Traverse and compare:
   - If overlapping → merge by updating end.
   - Else → push previous interval and start new one.
4. Add last interval.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size();

        sort(a.begin(), a.end());

        vector<vector<int>> res;

        int start1 = a[0][0];
        int end1 = a[0][1];

        for(int i = 1; i < n; i++) {
            int start2 = a[i][0];
            int end2 = a[i][1];

            if(end1 >= start2) {
                end1 = max(end1, end2);
            } 
            else {
                res.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }

        res.push_back({start1, end1});

        return res;
    }
};

/*
Key Learning:
1. Sort intervals before processing.
2. Overlap condition: current end >= next start.
3. Greedy merge to minimize intervals.
4. Base template for interval problems.
*/
