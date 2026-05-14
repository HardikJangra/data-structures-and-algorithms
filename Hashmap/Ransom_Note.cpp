/*
Problem: Ransom Note
Platform: LeetCode
Pattern: Hashing / Frequency Counting
Folder: 12_Hashing
Difficulty: Easy

Problem Statement:
Given two strings ransomNote and magazine,
return true if ransomNote can be constructed
using the letters from magazine.

Each letter in magazine can only be used once.

Approach:
1. Count frequency of all characters in magazine.
2. Traverse ransomNote:
   - If character frequency becomes zero,
     construction is impossible.
3. Otherwise decrease frequency and continue.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;

        // Count magazine characters
        for(char ch : magazine) {
            mp[ch]++;
        }

        // Try constructing ransom note
        for(char ch : ransomNote) {

            if(mp[ch] == 0) {
                return false;
            }

            mp[ch]--;
        }

        return true;
    }
};

/*
Key Learning:
1. HashMap useful for character availability tracking.
2. Frequency decrement pattern.
3. Greedy character consumption approach.
4. Common string hashing interview problem.
*/
