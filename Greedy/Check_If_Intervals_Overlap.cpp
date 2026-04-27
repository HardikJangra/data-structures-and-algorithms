/*
Problem: Check if Any Intervals Overlap
Platform: GeeksforGeeks
Pattern: Greedy + Sorting (Intervals)
Folder: 10_Greedy_Intervals
Difficulty: Easy

Problem Statement:
Given a list of intervals, determine if any two intervals overlap.

Return true if there is at least one overlapping pair, else false.

Approach:
1. Sort intervals based on start time.
2. Traverse intervals:
   - If current start <= previous end → overlap exists.
3. Return true immediately when overlap is found.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIntersect(vector<vector<int>> intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= intervals[i - 1][1]) {
                return true;
            }
        }

        return false;
    }
};

/*
Key Learning:
1. Always sort intervals before checking overlaps.
2. Only adjacent intervals need to be checked after sorting.
3. Greedy observation simplifies the problem.
4. Foundation for many interval problems.
*/
