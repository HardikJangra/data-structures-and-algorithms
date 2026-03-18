# Problem: Lowest Common Ancestor of a Binary Tree

## Problem Statement

Given a binary tree, find the **lowest common ancestor (LCA)** of two given nodes `p` and `q`.

The **lowest common ancestor** is defined as the lowest node in the tree that has both `p` and `q` as descendants.

A node can be a descendant of itself.

---

## Example

### Example 1

Input

```
root = [3,5,1,6,2,0,8,null,null,7,4]
p = 5
q = 1
```

Tree

```
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4
```

Output

```
3
```

---

### Example 2

Input

```
p = 5
q = 4
```

Output

```
5
```

Explanation

Node `5` is an ancestor of `4`, so it is the LCA.

---

## Approach: DFS (Recursive)

### Key Idea

- If we find either `p` or `q`, return it.
- Recursively search in left and right subtrees.
- If both left and right return non-null → current node is LCA.

---

## Steps

1. If `root == NULL`, return `NULL`.
2. If `root == p` or `root == q`, return `root`.
3. Recursively search left subtree.
4. Recursively search right subtree.
5. If both left and right are not null → return `root`.
6. Otherwise return the non-null result.

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

Where `h` is height of the tree (recursion stack).

Worst case:

```
O(n)
```

---

## C++ Implementation

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL)
            return NULL;

        if(root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != NULL && right != NULL)
            return root;

        if(left != NULL)
            return left;
        else
            return right;
    }
};
```

---

## Key Takeaways

- This is a classic **DFS recursion problem**.
- Uses **divide and conquer**.
- If both sides return a node → current node is LCA.
- If only one side returns → propagate it upward.

---

## Related Problems

- Lowest Common Ancestor in BST
- Path Sum
- Diameter of Binary Tree
