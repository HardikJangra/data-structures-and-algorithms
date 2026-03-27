# Problem: Convert Sorted Array to Binary Search Tree

## Problem Statement

Given an integer array `nums` where the elements are sorted in ascending order, convert it to a **height-balanced Binary Search Tree (BST)**.

A height-balanced BST is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

---

## Example

### Example 1

Input

```
nums = [-10,-3,0,5,9]
```

Output

```
[0,-3,9,-10,null,5]
```

Possible Tree

```
        0
       / \
     -3   9
     /   /
   -10  5
```

---

## Approach: Divide and Conquer

### Key Idea

To create a **height-balanced BST**:

- The **middle element** of the array should be the root.
- Left half → left subtree
- Right half → right subtree

This ensures the tree remains balanced.

---

## Steps

1. Find the middle element of the array.
2. Make it the root.
3. Recursively build left subtree from left half.
4. Recursively build right subtree from right half.

---

## Time Complexity

```
O(n)
```

Each element is used once to create a node.

---

## Space Complexity

```
O(log n)
```

Due to recursion stack (balanced tree).

---

## C++ Implementation

```cpp
class Solution {
public:
    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums, start, mid - 1);
        root->right = build(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};
```

---

## Key Takeaways

- Middle element becomes root → balanced BST.
- Divide and conquer approach.
- Important concept for building balanced trees.

---

## Related Problems

- Validate Binary Search Tree
- Insert into BST
- Balanced Binary Tree
- Construct BST from Sorted Array
