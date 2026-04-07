/*
Problem: 4Sum
Platform: LeetCode
Pattern: Two Pointers + Sorting
Difficulty: Medium

Problem Statement:
Given an array nums of n integers, return all unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct
- nums[a] + nums[b] + nums[c] + nums[d] == target

The solution set must not contain duplicate quadruplets.

Approach:
1. Sort the array.
2. Fix two elements (i and j).
3. Use two pointers (left and right) for the remaining two elements.
4. Skip duplicates for i, j, left, and right.
5. Use long long to avoid integer overflow.

Time Complexity: O(n^3)
Space Complexity: O(1) (excluding result)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while(left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if(sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

/*
Key Learning:
1. Extension of 3Sum → fix 2 elements instead of 1.
2. Always sort the array before applying two pointers.
3. Duplicate skipping is crucial.
4. Use long long to prevent overflow.
*/
