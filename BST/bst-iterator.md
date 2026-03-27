# Problem: Binary Search Tree Iterator

## Problem Statement

Implement the `BSTIterator` class that represents an iterator over the inorder traversal of a Binary Search Tree (BST).

The iterator should support the following operations:

- `BSTIterator(TreeNode* root)` → Initializes the iterator.
- `int next()` → Returns the next smallest number.
- `bool hasNext()` → Returns true if there exists a next number.

---

## Example

Input

```
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], []]
```

Output

```
[null, 3, 7, true, 9, true, 15, true]
```

---

## Approach: Controlled Inorder Traversal

### Key Idea

Inorder traversal of a BST gives values in **sorted order**.

Instead of storing the entire inorder traversal, we simulate it using a **stack** and push only left nodes.

This ensures:

- `next()` → O(1) amortized
- `hasNext()` → O(1)
- Space → O(h)

---

## Steps

1. Push all left nodes into the stack.
2. `next()`:
   - Pop top node.
   - If it has a right child → push all left nodes of right subtree.
3. `hasNext()`:
   - Return whether stack is empty or not.

---

## Time Complexity

| Operation | Complexity |
|----------|------------|
| next() | O(1) amortized |
| hasNext() | O(1) |

---

## Space Complexity

```
O(h)
```

Where `h` is the height of the tree.

---

## C++ Implementation

```cpp
class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (temp->right != NULL) {
            pushAllLeft(temp->right);
        }

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAllLeft(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }
};
```

---

## Key Takeaways

- This problem uses **iterative inorder traversal**.
- Stack stores only necessary nodes.
- Efficient iterator design pattern.

---

## Related Problems

- Kth Smallest Element in BST
- Inorder Traversal
- Validate BST
