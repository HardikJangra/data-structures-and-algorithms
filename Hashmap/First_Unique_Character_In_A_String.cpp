/*
Problem: First Unique Character in a String
Platform: LeetCode
Pattern: Hashing
Folder: 12_Hashing
Difficulty: Easy

Problem Statement:
Given a string s, find the first non-repeating character in it
and return its index.

If it does not exist, return -1.

Approach:
1. Count frequency of each character using hashmap.
2. Traverse string again:
   - First character with frequency 1 is answer.
3. Return -1 if no unique character exists.

Time Complexity: O(n)
Space Complexity: O(1) / O(26)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;

        // Count frequency
        for(char ch : s) {
            mp[ch]++;
        }

        // Find first unique character
        for(int i = 0; i < s.length(); i++) {
            if(mp[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

/*
Key Learning:
1. HashMap useful for frequency counting.
2. Two-pass traversal pattern:
   - First pass → frequency count
   - Second pass → answer extraction
3. Common hashing interview pattern.
4. Frequency maps simplify character problems.
*/
