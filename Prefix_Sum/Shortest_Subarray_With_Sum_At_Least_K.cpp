/*
Problem: Shortest Subarray with Sum at Least K
Platform: LeetCode
Pattern: Prefix Sum + Monotonic Deque
Folder: 09_Prefix_Sum
Difficulty: Hard

Problem Statement:
Given an integer array nums and an integer k,
return the length of the shortest non-empty subarray of nums
with sum at least k.

If there is no such subarray, return -1.

Approach:
1. Compute prefix sum array.
2. Use deque to store indices of prefix sums.
3. Maintain deque in increasing order of prefix values.
4. For each index j:
   - Check if prefix[j] - prefix[dq.front()] >= k
     → update answer and pop front.
   - Maintain monotonic increasing deque:
     remove larger prefix values from back.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;
        int ans = INT_MAX;

        for(int j = 0; j <= n; j++) {

            while(!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
                ans = min(ans, j - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefix[j] <= prefix[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

/*
Key Learning:
1. Sliding window fails due to negative numbers.
2. Prefix sum + deque handles non-monotonic sums.
3. Monotonic queue ensures optimal candidates.
4. Very advanced and important interview problem.
*/
