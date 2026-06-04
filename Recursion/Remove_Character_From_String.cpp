/*
Problem: Remove Character From String
Platform: GeeksforGeeks
Pattern: Recursion
Folder: 15_Recursion
Difficulty: Easy

Problem Statement:
Given a string s and a character c,
remove all occurrences of c from the string using recursion.

Example:
Input:
s = "geeksforgeeks"
c = 'e'

Output:
gksforgks

Approach:
1. Traverse string recursively.
2. If current character is not equal to c:
   - Add it to answer string.
3. Move to next index.
4. Base case:
   - Reached end of string.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(string &s,
               char c,
               int i,
               string &ans)
    {
        if(i == s.size()) {
            return;
        }

        if(s[i] != c) {
            ans.push_back(s[i]);
        }

        solve(s, c, i + 1, ans);
    }

    void removeCharacter(string &s, char c) {

        string ans;

        solve(s, c, 0, ans);

        s = ans;
    }
};

/*
Key Learning:
1. Process one character per recursive call.
2. Build answer while returning through recursion.
3. String filtering using recursion.
4. Classic recursion-on-string pattern.
*/
