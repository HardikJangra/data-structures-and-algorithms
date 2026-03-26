# Problem: Trim a Binary Search Tree

## Problem Statement

Given the root of a Binary Search Tree (BST) and two integers `low` and `high`, trim the tree so that all its elements lie in the range `[low, high]`.

Trimming the tree should not change the relative structure of the elements that will remain in the tree.

Return the root of the trimmed BST.

---

## Example

### Example 1

Input

```
root = [1,0,2]
low = 1
high = 2
```

Output

```
[1,null,2]
```

---

### Example 2

Input

```
root = [3,0,4,null,2,null,null,1]
low = 1
high = 3
```

Output

```
[3,2,null,1]
```

---

## Approach: Using BST Properties

### Key Idea

Since this is a **Binary Search Tree**, we can use the BST property:

```
Left subtree values < root value
Right subtree values > root value
```

So:

- If `root->val < low` → discard left subtree and move to right subtree
- If `root->val > high` → discard right subtree and move to left subtree
- Otherwise → keep the node and recursively trim left and right

---

## Steps

1. If root is NULL → return NULL.
2. If root value < low → return trimmed right subtree.
3. If root value > high → return trimmed left subtree.
4. Otherwise:
   - Trim left subtree
   - Trim right subtree
   - Return root

---

## Time Complexity

```
O(n)
```

We may visit all nodes once.

---

## Space Complexity

```
O(h)
```

Where `h` is height of the tree (recursion stack).

---

## C++ Implementation

```cpp
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) return NULL;

        if (root->val < low)
            return trimBST(root->right, low, high);

        if (root->val > high)
            return trimBST(root->left, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
```

---

## Key Takeaways

- BST property helps skip unnecessary nodes.
- We recursively adjust left and right subtrees.
- This is a **BST pruning problem**.

---

## Related Problems

- Validate Binary Search Tree
- Insert into BST
- Delete Node in BST
- Lowest Common Ancestor in BST
