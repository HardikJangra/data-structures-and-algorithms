/*
Problem: Remove All Adjacent Duplicates In String
Platform: LeetCode
Pattern: Stack
Folder: 11_Stack
Difficulty: Easy

Problem Statement:
Given a string s consisting of lowercase English letters,
remove all adjacent duplicate pairs repeatedly until no duplicates remain.

Return the final string.

Approach:
1. Use stack to process characters.
2. If current character equals stack top:
   - Remove duplicate by popping.
3. Else:
   - Push character into stack.
4. Build final answer from stack.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(char ch : s) {
            if(!st.empty() && st.top() == ch) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*
Key Learning:
1. Stack helps handle adjacent pair removal.
2. Push-pop simulates elimination process.
3. Useful for bracket/string processing problems.
4. Common stack interview pattern.
*/
