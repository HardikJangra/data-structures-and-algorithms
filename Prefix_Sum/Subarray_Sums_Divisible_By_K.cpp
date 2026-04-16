/*
Problem: Subarray Sums Divisible by K
Platform: LeetCode
Pattern: Prefix Sum + Modulo Hashing
Folder: 09_Prefix_Sum
Difficulty: Medium

Problem Statement:
Given an integer array nums and an integer k,
return the number of non-empty subarrays whose sum is divisible by k.

Approach:
1. Maintain running prefix sum.
2. Compute remainder = prefixSum % k.
3. If same remainder appeared before,
   then subarray between them has sum divisible by k.
4. Use hashmap to store frequency of remainders.
5. Normalize negative remainders using:
   ((sum % k) + k) % k

Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int rem = ((sum % k) + k) % k;

            if(mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            mp[rem]++;
        }

        return count;
    }
};

/*
Key Learning:
1. If two prefix sums have same remainder mod k,
   their difference is divisible by k.
2. Normalize negative modulo in C++ carefully.
3. Very common prefix-sum hashing trick.
4. Important interview pattern.
*/
