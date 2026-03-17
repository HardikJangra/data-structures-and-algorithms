# Problem: Balanced Binary Tree

## Problem Statement

Given a binary tree, determine if it is **height-balanced**.

A binary tree is balanced if:

```
|height(left subtree) - height(right subtree)| ≤ 1
```

for every node in the tree.

---

## Example

### Example 1

Input

```
root = [3,9,20,null,null,15,7]
```

Tree

```
      3
     / \
    9  20
       / \
      15  7
```

Output

```
true
```

---

### Example 2

Input

```
root = [1,2,2,3,3,null,null,4,4]
```

Output

```
false
```

---

## Approach: Optimized DFS

### Key Idea

Instead of calculating height separately for each node (which leads to O(n²)),  
we combine **height calculation and balance checking** in a single traversal.

We use a special value:

```
-1 → indicates the tree is NOT balanced
```

### Steps

1. Recursively compute height of left subtree.
2. If left subtree is unbalanced → return `-1`.
3. Recursively compute height of right subtree.
4. If right subtree is unbalanced → return `-1`.
5. If height difference > 1 → return `-1`.
6. Otherwise return height of current node.

---

## Time Complexity

```
O(n)
```

Each node is visited only once.

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

## C++ Implementation (Optimized)

```cpp
class Solution {
public:

    int height(TreeNode* root) {

        if(root == NULL)
            return 0;

        int left = height(root->left);
        if(left == -1)
            return -1;

        int right = height(root->right);
        if(right == -1)
            return -1;

        if(abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {

        if(height(root) == -1)
            return false;

        return true;
    }
};
```

---

## Key Takeaways

- This is an **optimized DFS solution**.
- Avoids repeated height calculation.
- Uses `-1` as a signal for imbalance.
- Important interview pattern:
  👉 **Combine computation + validation in one recursion**

---

## Related Problems

- Maximum Depth of Binary Tree
- Diameter of Binary Tree
- Same Tree
