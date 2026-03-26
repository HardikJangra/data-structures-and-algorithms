# Problem: Recover Binary Search Tree

## Problem Statement

You are given the root of a Binary Search Tree (BST), where the values of **exactly two nodes** were swapped by mistake. Recover the tree without changing its structure.

---

## Example

### Example 1

Input

```
root = [1,3,null,null,2]
```

Tree

```
    1
   /
  3
   \
    2
```

Output

```
[3,1,null,null,2]
```

---

### Example 2

Input

```
root = [3,1,4,null,null,2]
```

Output

```
[2,1,4,null,null,3]
```

---

## Approach: Inorder Traversal

### Key Idea

Inorder traversal of a BST should produce a **sorted sequence**.

If two nodes are swapped, the inorder sequence will have **two violations** where:

```
prev->val > current->val
```

We detect these two nodes and swap their values back.

---

## Steps

1. Perform inorder traversal.
2. Track previous node (`prev`).
3. If `prev->val > current->val`, then we found a violation.
4. Store the two incorrect nodes (`first` and `second`).
5. After traversal, swap their values.

---

## Time Complexity

```
O(n)
```

We traverse the tree once.

---

## Space Complexity

```
O(h)
```

Where `h` is height of tree (recursion stack).

---

## C++ Implementation

```cpp
class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);

        if (prev != NULL && prev->val > root->val) {
            if (first == NULL)
                first = prev;
            second = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};
```

---

## Key Takeaways

- Inorder traversal of BST = **sorted order**.
- If two nodes are swapped → order is violated.
- We detect the two nodes and swap them back.
- Important interview concept: **Detecting anomalies in inorder traversal**.

---

## Related Problems

- Validate Binary Search Tree
- Kth Smallest Element in BST
- Inorder Traversal
