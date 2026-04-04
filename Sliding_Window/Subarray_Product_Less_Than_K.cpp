/*
Problem: Subarray Product Less Than K
Platform: LeetCode
Pattern: Sliding Window
Difficulty: Medium

Problem Statement:
Given an array of integers nums and an integer k, return the number of contiguous 
subarrays where the product of all the elements in the subarray is strictly less than k.

Approach:
We use Sliding Window technique.
We maintain a window from left to right and keep track of the product of elements.
If product becomes greater than or equal to k, shrink the window from the left.
At each step, number of subarrays ending at right = (right - left + 1).

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int count = 0;
        int product = 1;
        int left = 0;

        for(int right = 0; right < nums.size(); right++) {
            product *= nums[right];

            while(product >= k) {
                product /= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};

/*
Key Learning:
1. Sliding window is used for subarray problems.
2. Maintain a window and adjust when condition breaks.
3. Number of subarrays = window size.
4. Very important pattern for interviews.
*/
