/*
Problem: Two Sum
Platform: LeetCode
Pattern: Two Pointers / Hash Map
Difficulty: Easy

Problem Statement:
Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the 
same element twice. You can return the answer in any order.

Approach:
We use a hashmap to store the elements we have already visited.
For each element, we calculate its complement = target - nums[i].
If the complement already exists in the hashmap, we found the solution.
Otherwise, we store the current element in the hashmap.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
