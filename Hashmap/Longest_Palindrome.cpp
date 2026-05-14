/*
Problem: Longest Palindrome
Platform: LeetCode
Pattern: Hashing / Frequency Counting
Folder: 12_Hashing
Difficulty: Easy

Problem Statement:
Given a string s consisting of uppercase and lowercase letters,
return the length of the longest palindrome that can be built
with those letters.

Letters are case-sensitive.

Approach:
1. Count frequency of each character.
2. Even frequency:
   - Use all occurrences.
3. Odd frequency:
   - Use frequency - 1
   - Keep one odd character for center.
4. Add 1 at end if any odd frequency exists.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        int length = 0;
        bool oddFound = false;

        for(auto it : mp) {

            if(it.second % 2 == 0) {
                length += it.second;
            }
            else {
                length += it.second - 1;
                oddFound = true;
            }
        }

        if(oddFound) {
            length += 1;
        }

        return length;
    }
};

/*
Key Learning:
1. Palindromes use pairs of characters.
2. Even counts fully contribute.
3. Only one odd character can sit in center.
4. Frequency counting simplifies palindrome problems.
*/
