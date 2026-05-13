/*
Problem: Simplify Path
Platform: LeetCode
Pattern: Stack + String Processing
Folder: 11_Stack
Difficulty: Medium

Problem Statement:
Given an absolute path for a Unix-style file system,
convert it into the simplified canonical path.

Rules:
- "."  → current directory
- ".." → parent directory
- Multiple "/" are treated as single "/"

Return the simplified path.

Approach:
1. Split path using '/' delimiter.
2. Use stack to process directory names.
3. Ignore:
   - empty strings
   - "."
4. For "..":
   - pop from stack if possible
5. Rebuild final canonical path from stack.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp;

        for(int i = 0; i <= path.size(); i++) {

            if(i == path.size() || path[i] == '/') {

                if(temp == "" || temp == ".") {
                    // Ignore
                }
                else if(temp == "..") {
                    if(!st.empty()) {
                        st.pop();
                    }
                }
                else {
                    st.push(temp);
                }

                temp = "";
            }
            else {
                temp += path[i];
            }
        }

        if(st.empty()) {
            return "/";
        }

        string ans = "";

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

/*
Key Learning:
1. Stack helps simulate directory traversal.
2. ".." means move one directory back.
3. Ignore "." and extra slashes.
4. Classic stack + string parsing problem.
*/
