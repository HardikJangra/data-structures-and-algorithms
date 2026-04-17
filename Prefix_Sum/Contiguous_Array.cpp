/*
Problem: Contiguous Array
Platform: LeetCode
Pattern: Prefix Sum + HashMap
Folder: 09_Prefix_Sum
Difficulty: Medium

Problem Statement:
Given a binary array nums, return the maximum length of a contiguous subarray
with an equal number of 0 and 1.

Approach:
1. Convert:
   0 → -1
   1 → +1

2. Maintain prefix sum.
3. If same prefix sum appears again,
   subarray between them has equal 0s and 1s.
4. Store first occurrence of each prefix sum in hashmap.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;
        int maxLen = 0;

        mp[0] = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                sum += -1;
            } else {
                sum += 1;
            }

            if(mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};

/*
Key Learning:
1. Convert problem to prefix sum using 0 → -1 trick.
2. Same prefix sum means equal number of 0s and 1s.
3. Store first occurrence to maximize subarray length.
4. Classic prefix sum + hashmap problem.
*/
