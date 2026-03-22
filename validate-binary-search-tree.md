# Problem: Validate Binary Search Tree

## Problem Statement

Given the root of a binary tree, determine if it is a **valid Binary Search Tree (BST)**.

A Binary Search Tree is valid if:

- The left subtree of a node contains only nodes with values **less than** the node's value.
- The right subtree of a node contains only nodes with values **greater than** the node's value.
- Both left and right subtrees must also be BSTs.

---

## Example

### Example 1

Input

```
root = [2,1,3]
```

Tree

```
    2
   / \
  1   3
```

Output

```
true
```

---

### Example 2

Input

```
root = [5,1,4,null,null,3,6]
```

Tree

```
    5
   / \
  1   4
     / \
    3   6
```

Output

```
false
```

Explanation

Node `3` is in the right subtree of `5` but is smaller than `5`, so it's not a valid BST.

---

## Approach: DFS with Range Validation

### Key Idea

Each node must lie within a valid range:

```
(minVal < node->val < maxVal)
```

- Left subtree → range becomes `(minVal, root->val)`
- Right subtree → range becomes `(root->val, maxVal)`

---

## Steps

1. Start with range `(-∞, +∞)`.
2. For each node:
   - Check if value is within range.
3. Recursively validate left subtree.
4. Recursively validate right subtree.

---

## Time Complexity

```
O(n)
```

Each node is visited once.

---

## Space Complexity

```
O(h)
```

Where `h` is the height of the tree (recursion stack).

Worst case:

```
O(n)
```

---

## C++ Implementation

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL)
            return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }
};
```

---

## Key Takeaways

- Checking only parent-child is not enough.
- Every node must satisfy a **range constraint**.
- This is a classic **DFS with constraints** problem.

---

## Related Problems

- Lowest Common Ancestor in BST
- Convert Sorted Array to BST
- Kth Smallest Element in BST
