/*
Problem: Reverse String
Platform: LeetCode
Pattern: Stack
Folder: 11_Stack
Difficulty: Easy

Problem Statement:
Write a function that reverses a string.
The input string is given as an array of characters.

You must do this by modifying the input array in-place.

Approach:
1. Push all characters into stack.
2. Pop characters one by one and place back into array.
3. Stack reverses order automatically (LIFO).

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        for(char c : s) {
            st.push(c);
        }

        int i = 0;

        while(!st.empty()) {
            s[i] = st.top();
            i++;
            st.pop();
        }
    }
};

/*
Key Learning:
1. Stack follows LIFO order.
2. Useful for reversal operations.
3. Simple introduction to stack applications.
4. Can also be optimized using two pointers with O(1) space.
*/
