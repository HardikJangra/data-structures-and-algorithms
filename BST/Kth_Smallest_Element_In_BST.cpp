/*
Problem: Kth Smallest Element In BST
Platform: LeetCode / GeeksforGeeks
Pattern: BST + Inorder Traversal
Folder: 16_BST
Difficulty: Medium

Problem Statement:
Given the root of a Binary Search Tree (BST)
and an integer k, return the kth smallest
element in the BST.

Approach:
1. Perform iterative inorder traversal.
2. Inorder traversal of BST gives nodes
   in sorted order.
3. Decrement k whenever a node is visited.
4. When k becomes 0, return current node.

Time Complexity: O(h + k)
Space Complexity: O(h)

where h = height of BST
*/

#include <bits/stdc++.h>
using namespace std;

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:

    int kthSmallest(Node *root, int k) {

        stack<Node*> st;
        Node* curr = root;

        while(curr != NULL || !st.empty()) {

            while(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            k--;

            if(k == 0) {
                return curr->data;
            }

            curr = curr->right;
        }

        return -1;
    }
};

/*
Key Learning:
1. Inorder traversal of BST gives sorted order.
2. kth smallest = kth node in inorder traversal.
3. Iterative inorder avoids recursion.
4. Very common BST interview problem.
*/
