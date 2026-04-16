/*
Problem: Subarray Sum Equals K
Platform: LeetCode
Pattern: Prefix Sum + HashMap
Folder: 09_Prefix_Sum
Difficulty: Medium

Problem Statement:
Given an array of integers nums and an integer k,
return the total number of subarrays whose sum equals to k.

Approach:
1. Maintain running prefix sum.
2. If (currentSum - k) exists in hashmap,
   then a subarray ending at current index sums to k.
3. Add frequency of (currentSum - k) to answer.
4. Store/update current prefix sum frequency.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int count = 0;
        int sum = 0;

        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};

/*
Key Learning:
1. Prefix sum helps convert subarray sum problem into lookup problem.
2. HashMap stores frequency of prefix sums.
3. Handles negative numbers unlike sliding window.
4. Fundamental interview pattern.
*/
