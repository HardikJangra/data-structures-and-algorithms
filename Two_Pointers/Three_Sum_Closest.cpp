/*
Problem: 3Sum Closest
Platform: LeetCode
Pattern: Two Pointers + Sorting
Difficulty: Medium

Problem Statement:
Given an integer array nums of length n and an integer target, 
find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

Approach:
1. Sort the array.
2. Fix one element and use two pointers (left and right).
3. Calculate sum and compare with target.
4. Update closest sum if current sum is closer to target.
5. Move left or right pointer accordingly.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }

                if(sum < target) {
                    left++;
                }
                else if(sum > target) {
                    right--;
                }
                else {
                    return sum;
                }
            }
        }

        return closestSum;
    }
};

/*
Key Learning:
1. Variation of 3Sum problem.
2. Instead of finding exact sum, track closest sum.
3. Use abs(target - sum) to compare closeness.
4. Two pointer + sorting pattern.
*/ee
