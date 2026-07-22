/*
Problem: House Robber
Platform: LeetCode
Pattern: Dynamic Programming (1D DP)
Folder: 19_Dynamic_Programming
Difficulty: Medium

Problem Statement:
You are a professional robber planning to rob houses
along a street.

Each house contains a certain amount of money.

Adjacent houses cannot be robbed.

Return the maximum amount of money you can rob.

Approach:
1. Define dp[i] as the maximum money that can be robbed
   from the first i houses.
2. For each house:
   - Rob current house:
       nums[i-1] + dp[i-2]
   - Skip current house:
       dp[i-1]
3. Take the maximum of both choices.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; i++) {

            int steal = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(steal, skip);
        }

        return dp[n];
    }
};

/*
Key Learning:
1. DP State:
   dp[i] = Maximum money from first i houses.
2. Decision:
   - Rob current house.
   - Skip current house.
3. Transition:
   dp[i] = max(nums[i-1] + dp[i-2], dp[i-1])
4. Classic "Take or Skip" DP pattern.
*/
