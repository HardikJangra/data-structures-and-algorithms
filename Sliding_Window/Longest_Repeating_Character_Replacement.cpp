/*
Problem: Longest Repeating Character Replacement
Platform: LeetCode
Pattern: Sliding Window + Frequency Tracking
Difficulty: Medium

Problem Statement:
You are given a string s and an integer k.
You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter
you can get after performing at most k replacements.

Approach:
1. Use sliding window.
2. Track frequency of characters in current window.
3. Maintain maxFreq = highest frequency char in window.
4. If characters to replace > k, shrink window.
   Condition:
   windowSize - maxFreq > k

Time Complexity: O(26 * n) ≈ O(n)
Space Complexity: O(26)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0, high = 0;
        int maxLen = 0;

        unordered_map<char, int> mp;

        while(high < s.size()) {
            mp[s[high]]++;

            int maxFreq = 0;
            for(auto it : mp) {
                maxFreq = max(maxFreq, it.second);
            }

            while((high - low + 1) - maxFreq > k) {
                mp[s[low]]--;

                if(mp[s[low]] == 0) {
                    mp.erase(s[low]);
                }

                low++;
            }

            maxLen = max(maxLen, high - low + 1);

            high++;
        }

        return maxLen;
    }
};

/*
Key Learning:
1. Window valid if replacements needed <= k.
2. Replacements needed = windowSize - maxFreq.
3. Track dominant character frequency.
4. Advanced sliding window optimization problem.
*/
