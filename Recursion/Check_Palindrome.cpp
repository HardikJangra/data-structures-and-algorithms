/*
Problem: Check Palindrome
Platform: GeeksforGeeks
Pattern: Recursion
Folder: 15_Recursion
Difficulty: Easy

Problem Statement:
Given a string s, determine whether it is a palindrome.

A palindrome reads the same forward and backward.

Approach:
1. Compare characters at both ends.
2. If they differ → return false.
3. Move inward recursively.
4. When left >= right, palindrome is confirmed.

Time Complexity: O(n)
Space Complexity: O(n)
(Recursion stack)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(string& s, int left, int right) {

        if(left >= right) {
            return true;
        }

        if(s[left] != s[right]) {
            return false;
        }

        return solve(s, left + 1, right - 1);
    }

    bool isPalindrome(string& s) {
        return solve(s, 0, s.size() - 1);
    }
};

/*
Key Learning:
1. Use two pointers recursively.
2. Compare outer characters first.
3. Shrink problem size in each recursive call.
4. Classic recursion pattern.
*/
