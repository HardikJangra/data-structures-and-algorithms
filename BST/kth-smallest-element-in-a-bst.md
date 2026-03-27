# Problem: Kth Smallest Element in a BST

## Problem Statement

Given the root of a Binary Search Tree (BST) and an integer `k`, return the **kth smallest value** (1-indexed) of all the values of the nodes in the tree.

---

## Example

### Example 1

Input

```
root = [3,1,4,null,2]
k = 1
```

Tree

```
      3
     / \
    1   4
     \
      2
```

Output

```
1
```

---

### Example 2

Input

```
root = [5,3,6,2,4,null,null,1]
k = 3
```

Output

```
3
```

---

## Approach: Inorder Traversal (Iterative)

### Key Idea

In a **Binary Search Tree**, inorder traversal gives nodes in **sorted order**.

```
Inorder Traversal = Left → Root → Right
```

So the **kth smallest element** is the kth node visited during inorder traversal.

---

## Steps

1. Use a stack to perform iterative inorder traversal.
2. Go to the leftmost node and push nodes onto stack.
3. Pop from stack → this is the next smallest element.
4. Decrement `k`.
5. When `k == 0`, return the node value.

---

## Time Complexity

```
O(h + k)
```

Where `h` is the height of the tree.

---

## Space Complexity

```
O(h)
```

For stack.

---

## C++ Implementation

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        
        while (true) {
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            k--;

            if (k == 0)
                return root->val;

            root = root->right;
        }
    }
};
```

---

## Key Takeaways

- Inorder traversal of BST gives **sorted order**.
- The kth visited node in inorder traversal is the kth smallest.
- Iterative traversal avoids recursion.

---

## Related Problems

- Validate Binary Search Tree
- Inorder Traversal
- Kth Largest Element in BST
