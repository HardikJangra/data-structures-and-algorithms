/*
Problem: Longest Substring with Exactly K Unique Characters
Platform: GeeksforGeeks
Pattern: Sliding Window + HashMap
Difficulty: Medium

Problem Statement:
Given a string s and an integer k, find the length of the longest substring
with exactly k unique characters.

Return -1 if no such substring exists.

Approach:
We use variable-size sliding window:
1. Expand window by moving right pointer.
2. Track character frequencies using hashmap.
3. If unique chars > k → shrink window from left.
4. If unique chars == k → update maximum length.

Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int low = 0;
        int high = 0;
        int maxCount = -1;

        unordered_map<char, int> mp;

        while(high < s.size()) {
            mp[s[high]]++;

            while(mp.size() > k) {
                mp[s[low]]--;

                if(mp[s[low]] == 0) {
                    mp.erase(s[low]);
                }

                low++;
            }

            if(mp.size() == k) {
                maxCount = max(maxCount, high - low + 1);
            }

            high++;
        }

        return maxCount;
    }
};

/*
Key Learning:
1. Sliding window with hashmap for frequency tracking.
2. Variable-size window with "exactly K" condition.
3. Common template for substring problems.
4. Foundation for many advanced sliding window problems.
*/
