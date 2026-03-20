# Problem: Symmetric Tree

## Problem Statement

Given the root of a binary tree, check whether it is a **mirror of itself** (i.e., symmetric around its center).

---

## Example

### Example 1

Input

```
root = [1,2,2,3,4,4,3]
```

Tree

```
        1
       / \
      2   2
     / \ / \
    3  4 4  3
```

Output

```
true
```

---

### Example 2

Input

```
root = [1,2,2,null,3,null,3]
```

Tree

```
        1
       / \
      2   2
       \   \
        3   3
```

Output

```
false
```

---

## Approach: DFS (Recursive Mirror Check)

### Key Idea

A tree is symmetric if:

```
Left subtree is a mirror of right subtree
```

To check this:

- Left child of left subtree == Right child of right subtree
- Right child of left subtree == Left child of right subtree

---

## Steps

1. Create a helper function `isMirror(left, right)`
2. If both nodes are NULL → return true
3. If one is NULL → return false
4. Check:
   - values are equal
   - left->left vs right->right
   - left->right vs right->left
5. Call helper on root’s left and right

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

Where `h` is height of the tree (recursion stack).

Worst case:

```
O(n)
```

---

## C++ Implementation (DFS)

```cpp
class Solution {
public:

    bool isMirror(TreeNode* left, TreeNode* right) {

        // Both NULL → symmetric
        if(left == NULL && right == NULL)
            return true;

        // One NULL → not symmetric
        if(left == NULL || right == NULL)
            return false;

        // Values must match + mirror condition
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};
```

---

## Alternative Approach (BFS)

We can also solve this using a queue:

- Push left and right nodes together
- Compare them level by level

---

## Key Takeaways

- Symmetry = mirror structure + equal values
- Recursion helps compare opposite branches
- Important pattern:
  👉 **Compare left-left with right-right AND left-right with right-left**

---

## Related Problems

- Same Tree
- Invert Binary Tree
- Balanced Binary Tree
