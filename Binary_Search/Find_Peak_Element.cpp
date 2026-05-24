/*
Problem: Find Peak Element
Platform: LeetCode
Pattern: Binary Search
Folder: 13_Binary_Search
Difficulty: Medium

Problem Statement:
A peak element is an element that is strictly greater
than its neighbors.

Given an integer array nums,
find a peak element and return its index.

You may assume:
nums[-1] = nums[n] = -∞

Approach:
1. Use binary search on slope direction.
2. If nums[mid] > nums[mid + 1]:
   - Peak lies on left side (including mid)
3. Else:
   - Peak lies on right side
4. Continue until low == high.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[mid + 1]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return high;
    }
};

/*
Key Learning:
1. Binary search can find local optimum.
2. Compare neighboring elements to detect direction.
3. Increasing slope → move right.
4. Decreasing slope → move left.
*/
