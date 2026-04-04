/*
Problem: 3Sum
Platform: LeetCode
Pattern: Two Pointers + Sorting
Difficulty: Medium

Problem Statement:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

The solution set must not contain duplicate triplets.

Approach:
1. First, sort the array.
2. Fix one element and use two pointers (left and right) to find the other two elements.
3. Skip duplicates to avoid repeating triplets.
4. If sum == 0 → store triplet.
5. If sum < 0 → move left pointer.
6. If sum > 0 → move right pointer.

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding result)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while(left < right && nums[left] == nums[left+1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right-1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if(sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};

/*
Key Learning:
1. Sorting helps apply two pointer technique.
2. Always skip duplicates in 3Sum.
3. Two pointer reduces complexity from O(n^3) to O(n^2).
4. Very important interview problem.
*/
