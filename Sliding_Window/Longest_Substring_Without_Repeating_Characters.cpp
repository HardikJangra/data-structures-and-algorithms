/*
Problem: Longest Substring Without Repeating Characters
Platform: LeetCode
Pattern: Sliding Window + HashMap
Difficulty: Medium

Problem Statement:
Given a string s, find the length of the longest substring
without repeating characters.

Approach:
We use variable-size sliding window:
1. Expand right pointer and add character frequency.
2. If duplicate occurs, shrink window from left
   until window becomes valid again.
3. Track maximum valid window length.

Time Complexity: O(n)
Space Complexity: O(1) / O(128)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;

        unordered_map<char, int> mp;

        while(right < s.size()) {
            mp[s[right]]++;

            while(mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};

/*
Key Learning:
1. Sliding window for unique character constraints.
2. Shrink window when duplicate appears.
3. Track max valid window size.
4. Foundation for advanced substring problems.
*/
