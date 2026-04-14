/*
Problem: Max Consecutive Ones III
Platform: LeetCode
Pattern: Sliding Window (At Most K Zeros)
Difficulty: Medium

Problem Statement:
Given a binary array nums and an integer k,
return the maximum number of consecutive 1's in the array
if you can flip at most k zeros.

Approach:
1. Use sliding window.
2. Track number of zeros in current window.
3. If zero count exceeds k, shrink window from left.
4. Maximum valid window size is the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for(int right = 0; right < nums.size(); right++) {

            if(nums[right] == 0)
                zeroCount++;

            while(zeroCount > k) {
                if(nums[left] == 0)
                    zeroCount--;

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

/*
Key Learning:
1. Sliding window with at most K invalid elements.
2. Common pattern for "flip/replace at most K".
3. Shrink when constraint breaks.
4. Same pattern as Character Replacement.
*/
