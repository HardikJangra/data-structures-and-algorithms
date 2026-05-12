/*
Problem: Next Greater Element II
Platform: LeetCode
Pattern: Monotonic Stack
Folder: 11_Stack
Difficulty: Medium

Problem Statement:
Given a circular integer array nums, return the next greater number
for every element in nums.

The next greater number of a number x is the first greater number
to its traversing-order next in the array.

If it doesn't exist, return -1.

Approach:
1. Use a monotonic decreasing stack.
2. Traverse array twice from right to left
   to simulate circular behavior.
3. Remove elements smaller than or equal to current.
4. Stack top becomes next greater element.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 2 * n - 1; i >= 0; i--) {
            int curr = nums[i % n];

            while(!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if(i < n) {
                if(!st.empty()) {
                    ans[i] = st.top();
                }
            }

            st.push(curr);
        }

        return ans;
    }
};

/*
Key Learning:
1. Monotonic stack maintains decreasing order.
2. Traverse twice for circular arrays.
3. Stack top gives next greater element.
4. Classic next greater element pattern.
*/
