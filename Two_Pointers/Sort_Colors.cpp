/*
Problem: Sort Colors (Dutch National Flag Problem)
Platform: LeetCode
Pattern: Two Pointers / 3-Way Partitioning
Difficulty: Medium

Problem Statement:
Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order 
red (0), white (1), and blue (2).

You must solve this problem without using the library's sort function.

Approach:
We use the Dutch National Flag Algorithm.
We maintain three pointers:
- low → for 0s
- mid → current element
- high → for 2s

If nums[mid] == 0 → swap with low and move both.
If nums[mid] == 1 → move mid.
If nums[mid] == 2 → swap with high and move high.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*
Key Learning:
1. Dutch National Flag algorithm.
2. Three pointer partitioning.
3. Very important sorting algorithm for arrays with limited values.
4. In-place sorting algorithm.
*/
