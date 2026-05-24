/*
Problem: Find First and Last Position of Element in Sorted Array
Platform: LeetCode
Pattern: Binary Search
Folder: 13_Binary_Search
Difficulty: Medium

Problem Statement:
Given a sorted array nums and a target value,
find the starting and ending position of the target.

If target is not found, return [-1, -1].

Approach:
1. Use binary search twice:
   - First occurrence
   - Last occurrence
2. For first occurrence:
   - Move left after finding target.
3. For last occurrence:
   - Move right after finding target.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int firstOccurence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);

        ans[0] = firstOccurence(nums, target);
        ans[1] = lastOccurence(nums, target);

        return ans;
    }
};

/*
Key Learning:
1. Binary search can find boundaries.
2. Modify search direction after finding target.
3. First occurrence → move left.
4. Last occurrence → move right.
*/
