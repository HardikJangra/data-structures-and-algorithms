# Problem: Insert into a Binary Search Tree

## Problem Statement

Given the root node of a Binary Search Tree (BST) and a value `val`, insert the value into the BST and return the root of the BST.

The insertion should maintain the BST property.

A Binary Search Tree (BST) has the following property:

```
Left subtree values < root value
Right subtree values > root value
```

---

## Example

### Example 1

Input

```
root = [4,2,7,1,3]
val = 5
```

Tree before insertion

```
        4
       / \
      2   7
     / \
    1   3
```

Tree after insertion

```
        4
       / \
      2   7
     / \  /
    1   3 5
```

---

### Example 2

Input

```
root = [40,20,60,10,30,50,70]
val = 25
```

Output

BST after inserting 25.

---

## Approach: Recursive Insertion

### Key Idea

Use BST property:

- If `val < root->val` → go to left subtree
- If `val > root->val` → go to right subtree
- Insert when we reach a `NULL` position

---

## Steps

1. If root is `NULL`, create a new node and return it.
2. If `val < root->val`, insert into left subtree.
3. Else insert into right subtree.
4. Return root.

---

## Time Complexity

```
O(h)
```

Where `h` is the height of the tree.

- Balanced tree → `O(log n)`
- Skewed tree → `O(n)`

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};
```

---

## Key Takeaways

- BST insertion follows **recursive traversal**.
- Insert at the correct leaf position.
- Important BST operation used in many problems.

---

## Related Problems

- Search in BST
- Delete Node in BST
- Validate BST
- Lowest Common Ancestor in BST
