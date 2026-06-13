/*
Problem: Minimum Depth of Binary Tree
Platform: LeetCode
Pattern: Trees + Recursion (DFS)
Folder: 14_Trees
Difficulty: Easy

Problem Statement:
Given the root of a binary tree, return its minimum depth.

The minimum depth is the number of nodes along the shortest
path from the root node down to the nearest leaf node.

Approach:
1. If the tree is empty, return 0.
2. If the current node is a leaf, return 1.
3. If one child is missing, recurse on the existing child.
4. If both children exist, take the minimum depth of the two.
5. Add 1 for the current node.

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
    int minDepth(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        // Leaf node
        if(root->left == NULL && root->right == NULL) {
            return 1;
        }

        // Only right subtree exists
        if(root->left == NULL) {
            return 1 + minDepth(root->right);
        }

        // Only left subtree exists
        if(root->right == NULL) {
            return 1 + minDepth(root->left);
        }

        // Both subtrees exist
        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }
};

/*
Key Learning:
1. Minimum depth is the shortest path to a LEAF node.
2. Do not use min(left, right) when one child is NULL.
3. Handle single-child cases separately.
4. Classic recursive DFS problem on binary trees.
*/
