/*
Problem: Minimum Size Subarray Sum
Platform: LeetCode
Pattern: Sliding Window
Difficulty: Medium

Problem Statement:
Given an array of positive integers nums and a positive integer target,
return the minimal length of a contiguous subarray whose sum is 
greater than or equal to target.

If no such subarray exists, return 0.

Approach:
We use variable-size sliding window.
1. Expand window by moving right pointer.
2. Keep adding elements to sum.
3. When sum >= target:
   - Update minimum length
   - Shrink window from left.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int minL = INT_MAX;
        int n = nums.size();

        while(j < n) {
            sum += nums[j];

            while(sum >= target) {
                minL = min(minL, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return minL == INT_MAX ? 0 : minL;
    }
};

/*
Key Learning:
1. Variable size sliding window.
2. Expand until condition satisfied.
3. Shrink to optimize answer.
4. Very common interview template.
*/
