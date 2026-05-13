/*
Problem: Remove All Adjacent Duplicates In String II
Platform: LeetCode
Pattern: Stack
Folder: 11_Stack
Difficulty: Medium

Problem Statement:
Given a string s and an integer k,
remove all adjacent duplicates in the string where
exactly k consecutive identical characters appear.

Repeat until no more removals can be made.

Return the final string.

Approach:
1. Use stack storing:
   {character, frequency}
2. If current character matches stack top:
   - Increase frequency
   - Remove when frequency reaches k
3. Otherwise push new character with count 1.
4. Rebuild final string from stack.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for(char ch : s) {

            if(!st.empty() && st.top().first == ch) {
                st.top().second++;

                if(st.top().second == k) {
                    st.pop();
                }
            }
            else {
                st.push({ch, 1});
            }
        }

        string ans = "";

        while(!st.empty()) {
            char ch = st.top().first;
            int count = st.top().second;

            while(count--) {
                ans += ch;
            }

            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*
Key Learning:
1. Stack can store extra metadata (frequency).
2. Pair stack useful for grouped character processing.
3. Remove block when frequency reaches k.
4. Extension of adjacent duplicate removal problem.
*/
