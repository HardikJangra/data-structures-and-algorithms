# Problem: Path Sum

## Problem Statement

Given the root of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf path** such that adding up all the values along the path equals `targetSum`.

A **leaf node** is a node with no children.

---

## Example

### Example 1

Input

```
root = [5,4,8,11,null,13,4,7,2,null,null,null,1]
targetSum = 22
```

Tree

```
        5
       / \
      4   8
     /   / \
    11  13  4
   /  \        \
  7    2        1
```

Output

```
true
```

Explanation

Path:

```
5 → 4 → 11 → 2 = 22
```

---

### Example 2

Input

```
root = [1,2,3]
targetSum = 5
```

Output

```
false
```

---

## Approach: DFS (Recursion)

### Key Idea

We recursively traverse the tree and subtract the current node value from `targetSum`.

At each step:

- Reduce the remaining sum.
- If we reach a leaf node, check if the remaining sum equals the node value.

---

## Steps

1. If the node is `NULL`, return `false`.
2. If the node is a **leaf node**:
   - Check if `targetSum == node->val`
3. Subtract current node value from `targetSum`.
4. Recursively check left and right subtree.

---

## Time Complexity

```
O(n)
```

We visit each node once.

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
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root == NULL)
            return false;

        // If it's a leaf node
        if(root->left == NULL && root->right == NULL) {
            return targetSum == root->val;
        }

        int remainingSum = targetSum - root->val;

        return hasPathSum(root->left, remainingSum) ||
               hasPathSum(root->right, remainingSum);
    }
};
```

---

## Key Takeaways

- Classic **DFS recursion problem**.
- Always check **leaf node condition carefully**.
- Instead of storing path sum, we reduce the target.
- Common pattern:
  👉 **Pass remaining value down recursion**

---

## Related Problems

- Path Sum II
- Path Sum III
- Maximum Path Sum
