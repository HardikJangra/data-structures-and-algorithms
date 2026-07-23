/*
Problem: Target Sum
Platform: LeetCode
Pattern: Dynamic Programming (Memoization)
Folder: 19_Dynamic_Programming
Difficulty: Medium

Problem Statement:
You are given an integer array nums and an integer target.

Assign either '+' or '-' before each number such that
the resulting expression evaluates to target.

Return the number of different expressions that evaluate
to the target.

Approach:
1. At every index, we have two choices:
   - Add the current number.
   - Subtract the current number.
2. Use recursion to explore both choices.
3. Memoize states using:
   (index, currentSum)
4. Return the total number of valid expressions.

Time Complexity: O(n × Range)
Space Complexity: O(n × Range)

where Range represents the possible values of currentSum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>& nums,
              int &target,
              int i,
              int sum,
              unordered_map<string, int>& memo)
    {
        if(i == nums.size()) {
            return (sum == target);
        }

        string key = to_string(i) + "," + to_string(sum);

        if(memo.find(key) != memo.end()) {
            return memo[key];
        }

        int plus = solve(nums,
                         target,
                         i + 1,
                         sum + nums[i],
                         memo);

        int minus = solve(nums,
                          target,
                          i + 1,
                          sum - nums[i],
                          memo);

        memo[key] = plus + minus;

        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        unordered_map<string, int> memo;

        return solve(nums,
                     target,
                     0,
                     0,
                     memo);
    }
};

/*
Key Learning:
1. Every element has two choices:
   +nums[i] or -nums[i].
2. DP State:
   (index, currentSum)
3. Memoization avoids recomputing identical states.
4. Classic recursion + memoization problem.
*/
