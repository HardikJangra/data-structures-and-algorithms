/*
Problem: Binary Search
Platform: LeetCode
Pattern: Binary Search
Folder: 13_Binary_Search
Difficulty: Easy

Problem Statement:
Given a sorted array of integers nums and an integer target,
return the index of target if it exists in the array.

Otherwise, return -1.

Approach:
1. Initialize low and high pointers.
2. Find middle element.
3. Compare:
   - If target found → return index
   - If target greater → search right half
   - Else → search left half
4. Continue until low > high.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

/*
Key Learning:
1. Binary Search works on sorted arrays.
2. Eliminate half search space each step.
3. Use safe midpoint formula:
   mid = low + (high - low) / 2
4. Fundamental searching algorithm.
*/
