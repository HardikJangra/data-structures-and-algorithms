/*
Problem: Insert Interval
Platform: LeetCode
Pattern: Greedy + Interval Merging
Folder: 10_Greedy_Intervals
Difficulty: Medium

Problem Statement:
You are given an array of non-overlapping intervals sorted by start time.
Insert a new interval into the intervals such that the resulting intervals
remain non-overlapping and sorted.

Approach:
1. Add all intervals completely before newInterval.
2. Merge all overlapping intervals with newInterval.
3. Add remaining intervals after merging.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;

        int i = 0;
        int start1 = newInterval[0];
        int end1 = newInterval[1];

        // Step 1: Add intervals before newInterval
        while(i < n && intervals[i][1] < start1) {
            res.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while(i < n && intervals[i][0] <= end1) {
            start1 = min(start1, intervals[i][0]);
            end1 = max(end1, intervals[i][1]);
            i++;
        }

        res.push_back({start1, end1});

        // Step 3: Add remaining intervals
        while(i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

/*
Key Learning:
1. Intervals are already sorted → no need to sort again.
2. Handle 3 cases:
   - Before overlap
   - Overlapping
   - After overlap
3. Greedy merging pattern.
4. Extension of Merge Intervals.
*/
