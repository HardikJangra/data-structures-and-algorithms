/*
Problem: Maximum Depth of Binary Tree
Platform: LeetCode
Pattern: Trees + Recursion (DFS)
Folder: 14_Trees
Difficulty: Easy

Problem Statement:
Given the root of a binary tree,
return its maximum depth.

The maximum depth is the number of nodes
along the longest path from the root
down to the farthest leaf node.

Approach:
1. If the tree is empty, return 0.
2. Recursively compute:
   - Maximum depth of left subtree.
   - Maximum depth of right subtree.
3. Return:
   1 + max(leftDepth, rightDepth)

Time Complexity: O(n)
Space Complexity: O(h)

where h is the height of the tree.
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

    int maxDepth(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        return 1 +
               max(maxDepth(root->left),
                   maxDepth(root->right));
    }
};

/*
Key Learning:
1. Maximum depth = longest root-to-leaf path.
2. Solve recursively for left and right subtrees.
3. Take maximum of both depths.
4. Fundamental DFS recursion problem.
*/
