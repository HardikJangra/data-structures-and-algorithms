/*
Problem: Binary Tree Inorder Traversal
Platform: LeetCode
Pattern: Trees + Iterative DFS + Stack
Folder: 14_Trees
Difficulty: Easy

Problem Statement:
Given the root of a binary tree,
return its inorder traversal.

Inorder Traversal:
Left → Root → Right

Approach:
1. Use a stack to simulate recursion.
2. Keep moving left and push nodes into stack.
3. When no left child exists:
   - Process current node.
   - Move to right subtree.
4. Continue until stack becomes empty.

Time Complexity: O(n)
Space Complexity: O(h)
where h = height of tree
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode*> st;
        vector<int> result;

        TreeNode* curr = root;

        while(curr != NULL || !st.empty()) {

            while(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            result.push_back(curr->val);

            curr = curr->right;
        }

        return result;
    }
};

/*
Key Learning:
1. Inorder Traversal = Left → Root → Right.
2. Stack simulates recursive call stack.
3. Push all left nodes first.
4. Fundamental iterative tree traversal.
*/
