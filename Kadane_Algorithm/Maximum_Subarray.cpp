/*
Problem: Maximum Subarray
Platform: LeetCode
Pattern: Kadane’s Algorithm
Folder: 08_Kadane_Algorithm
Difficulty: Medium

Problem Statement:
Given an integer array nums, find the contiguous subarray
with the largest sum and return its sum.

Approach:
Kadane’s Algorithm:
1. Maintain currentSum = max(current element, currentSum + current element)
2. Update maxSum with the best seen so far
3. Return maxSum

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

/*
Key Learning:
1. Kadane’s Algorithm finds maximum subarray sum in O(n).
2. At each index, choose whether to start fresh or extend previous subarray.
3. Core pattern for contiguous subarray optimization problems.
4. Very frequently asked in interviews.
*/
