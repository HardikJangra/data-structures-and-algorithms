/*
Problem: Maximum Number Of Balloons
Platform: LeetCode
Pattern: Hashing / Frequency Counting
Folder: 12_Hashing
Difficulty: Easy

Problem Statement:
Given a string text, return the maximum number of instances
of the word "balloon" that can be formed using the characters in text.

Each character can be used at most once.

Approach:
1. Count frequency of all characters using hashmap.
2. Word "balloon" requires:
   - b → 1
   - a → 1
   - l → 2
   - o → 2
   - n → 1
3. Answer is minimum possible complete formation.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for(char ch : text) {
            mp[ch]++;
        }

        return min({
            mp['b'],
            mp['a'],
            mp['l'] / 2,
            mp['o'] / 2,
            mp['n']
        });
    }
};

/*
Key Learning:
1. Frequency counting using hashmap.
2. Carefully handle repeated characters.
3. Minimum available required frequency determines answer.
4. Common character counting pattern.
*/
