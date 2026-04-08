/*
Problem: Backspace String Compare
Platform: LeetCode
Pattern: Two Pointers (Reverse Traversal)
Difficulty: Easy

Problem Statement:
Given two strings s and t, return true if they are equal when both are typed into empty text editors.
'#' means a backspace character.

Approach:
We traverse both strings from the end using two pointers.
We simulate backspace using skip counters:
- If '#' is found → increase skip count.
- If skip > 0 → skip the character.
- Otherwise → compare characters.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        int skipS = 0, skipT = 0;

        while(i >= 0 || j >= 0) {

            while(i >= 0) {
                if(s[i] == '#') {
                    skipS++;
                    i--;
                }
                else if(skipS > 0) {
                    skipS--;
                    i--;
                }
                else break;
            }

            while(j >= 0) {
                if(t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if(skipT > 0) {
                    skipT--;
                    j--;
                }
                else break;
            }

            if(i >= 0 && j >= 0) {
                if(s[i] != t[j]) return false;
            }
            else {
                if(i >= 0 || j >= 0) return false;
            }

            i--;
            j--;
        }

        return true;
    }
};

/*
Key Learning:
1. Reverse traversal avoids extra space.
2. Skip counters simulate backspace efficiently.
3. Better than using stack (O(1) space vs O(n)).
4. Classic optimized string problem.
*/
