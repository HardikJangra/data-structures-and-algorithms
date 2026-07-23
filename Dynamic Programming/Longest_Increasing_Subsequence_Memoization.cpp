/*
Problem: Longest Increasing Subsequence
Platform: LeetCode
Pattern: Dynamic Programming (Memoization)
Folder: 19_Dynamic_Programming
Difficulty: Medium

Problem Statement:
Given an integer array nums,
return the length of the longest strictly increasing
subsequence.

A subsequence can be obtained by deleting some or
no elements without changing the order of the
remaining elements.

Approach:
1. At every index, we have two choices:
   - Take the current element (if it is increasing).
   - Skip the current element.
2. DP State:
   (previous index, current index)
3. Memoize computed states.
4. Return the maximum of both choices.

Time Complexity: O(n²)
Space Complexity: O(n²)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    int t[2501][2501];

    int lis(vector<int>& nums,
            int prev_idx,
            int curr_idx)
    {
        if(curr_idx == n) {
            return 0;
        }

        if(prev_idx != -1 &&
           t[prev_idx][curr_idx] != -1) {
            return t[prev_idx][curr_idx];
        }

        int taken = 0;

        if(prev_idx == -1 ||
           nums[curr_idx] > nums[prev_idx]) {

            taken = 1 +
                    lis(nums,
                        curr_idx,
                        curr_idx + 1);
        }

        int not_taken =
        lis(nums,
            prev_idx,
            curr_idx + 1);

        if(prev_idx != -1) {
            t[prev_idx][curr_idx] =
            max(taken, not_taken);
        }

        return max(taken, not_taken);
    }

    int lengthOfLIS(vector<int>& nums) {

        memset(t, -1, sizeof(t));

        n = nums.size();

        return lis(nums, -1, 0);
    }
};

/*
Key Learning:
1. Every element has two choices:
   - Take
   - Skip
2. DP State:
   (previous index, current index)
3. Memoization avoids repeated computations.
4. Classic subsequence DP problem.
*/
