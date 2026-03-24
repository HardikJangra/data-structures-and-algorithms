# Problem: Lowest Common Ancestor in a Binary Search Tree

## Problem Statement

Given a **Binary Search Tree (BST)**, find the **Lowest Common Ancestor (LCA)** of two given nodes `p` and `q`.

The **Lowest Common Ancestor** is defined as the lowest node in the tree that has both `p` and `q` as descendants.

A node can be a descendant of itself.

---

## Example

### Example 1

Input

```
root = [6,2,8,0,4,7,9,null,null,3,5]
p = 2
q = 8
```

Tree

```
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5
```

Output

```
6
```

---

### Example 2

Input

```
p = 2
q = 4
```

Output

```
2
```

Explanation

Node `2` is an ancestor of `4`, so it is the LCA.

---

## Approach: Using BST Properties

### Key Idea

In a BST:

```
Left subtree values < root value
Right subtree values > root value
```

So:

- If both `p` and `q` are smaller than root → LCA is in left subtree
- If both `p` and `q` are greater than root → LCA is in right subtree
- Otherwise → current node is the LCA

---

## Steps

1. If root is NULL → return NULL.
2. If both nodes are smaller than root → go left.
3. If both nodes are greater than root → go right.
4. Otherwise → root is the LCA.

---

## Time Complexity

```
O(h)
```

Where `h` is the height of the BST.

- Balanced BST → `O(log n)`
- Skewed BST → `O(n)`

---

## Space Complexity

```
O(h)
```

Recursion stack.

---

## C++ Implementation

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case
        if (root == NULL)
            return NULL;

        // If both nodes are smaller than root → go left
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        // If both nodes are greater than root → go right
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        // If one node is on left and other on right → root is LCA
        return root;
    }
};
```

---

## Key Takeaways

- Uses **BST property** to reduce search space.
- Faster than general binary tree LCA.
- No need to traverse entire tree.

---

## Related Problems

- Validate Binary Search Tree
- Insert into BST
- Delete Node in BST
- Kth Smallest Element in BST
