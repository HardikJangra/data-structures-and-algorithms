# Problem: Invert Binary Tree

## Problem Statement

Given the root of a binary tree, invert the tree and return its root.

Inverting a binary tree means swapping the left and right children of every node.

---

## Example

### Example 1

Input

```
root = [4,2,7,1,3,6,9]
```

Tree representation

```
        4
       / \
      2   7
     / \ / \
    1  3 6  9
```

Output

```
[4,7,2,9,6,3,1]
```

Inverted Tree

```
        4
       / \
      7   2
     / \ / \
    9  6 3  1
```

---

### Example 2

Input

```
root = [2,1,3]
```

Output

```
[2,3,1]
```

---

## Approach 1: Breadth First Search (BFS)

We use a **queue** to traverse the tree level by level.

### Steps

1. If root is `NULL`, return `NULL`.
2. Push root into queue.
3. While queue is not empty:
   - Pop a node.
   - Swap its left and right children.
   - Push its children into the queue.

---

## Time Complexity

```
O(n)
```

Each node is visited once.

---

## Space Complexity

```
O(n)
```

Queue may store all nodes at a level.

---

## C++ Implementation (BFS)

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL)
            return NULL;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            swap(node->left, node->right);

            if(node->left)
                q.push(node->left);

            if(node->right)
                q.push(node->right);
        }

        return root;
    }
};
```

---

## Approach 2: Depth First Search (DFS)

We use **recursion** to invert the tree.

### Key Idea

- Recursively invert left subtree.
- Recursively invert right subtree.
- Swap them.

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

Where `h` is height of tree (recursion stack).

Worst case:

```
O(n)
```

---

## C++ Implementation (DFS)

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL)
            return NULL;

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};
```

---

## Key Takeaways

- This is a fundamental tree problem.
- Can be solved using both:
  - BFS (queue)
  - DFS (recursion)
- Helps understand tree traversal and manipulation.

---

## Related Problems

- Same Tree
- Symmetric Tree
- Maximum Depth of Binary Tree
