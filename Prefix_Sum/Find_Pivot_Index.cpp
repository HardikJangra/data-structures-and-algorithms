/*
Problem: Find Pivot Index
Platform: LeetCode
Pattern: Prefix Sum
Folder: 09_Prefix_Sum
Difficulty: Easy

Problem Statement:
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where:
- Sum of all numbers strictly to the left equals
- Sum of all numbers strictly to the right

Return the leftmost pivot index.
If no such index exists, return -1.

Approach:
1. Compute total sum of array.
2. Maintain leftSum while traversing.
3. rightSum = totalSum - leftSum - nums[i]
4. If leftSum == rightSum, return i.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int leftSum = 0;

        for(int x : nums) {
            sum += x;
        }

        for(int i = 0; i < nums.size(); i++) {
            int rightSum = sum - leftSum - nums[i];

            if(rightSum == leftSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};

/*
Key Learning:
1. Prefix sum can optimize left/right sum checks.
2. Avoid recomputing left/right sums for every index.
3. Common balance/equilibrium array pattern.
4. O(n) solution instead of O(n²).
*/
