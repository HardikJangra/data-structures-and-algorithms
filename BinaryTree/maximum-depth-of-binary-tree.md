# Problem: Maximum Depth of Binary Tree

## Problem Statement

Given the root of a binary tree, return its **maximum depth**.

The **maximum depth** of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

---

## Example

### Example 1

Input

```
root = [3,9,20,null,null,15,7]
```

Tree representation

```
      3
     / \
    9  20
       / \
      15  7
```

Output

```
3
```

---

### Example 2

Input

```
root = [1,null,2]
```

Tree representation

```
    1
     \
      2
```

Output

```
2
```

---

## Approach

We solve this problem using **Depth First Search (DFS)**.

The depth of a node is:

```
1 + max(depth of left subtree, depth of right subtree)
```

### Steps

1. If the root is `NULL`, return `0`.
2. Recursively calculate the depth of the left subtree.
3. Recursively calculate the depth of the right subtree.
4. Return the maximum depth between the two plus one for the current node.

---

## Time Complexity

```
O(n)
```

We visit each node exactly once.

---

## Space Complexity

```
O(h)
```

Where `h` is the height of the tree due to recursion stack.

Worst case (skewed tree):

```
O(n)
```

---

## C++ Implementation (Recursive DFS)

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};
```

---

## Iterative Approach (Using BFS)

We can also solve this problem using **Breadth First Search (Level Order Traversal)**.

### Idea

Traverse the tree level by level and count the number of levels.

---

## C++ Implementation (BFS)

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                TreeNode* node = q.front();
                q.pop();

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            depth++;
        }

        return depth;
    }
};
```

---

## Key Takeaways

- Maximum depth is the **height of the binary tree**.
- DFS recursion is the most common approach.
- BFS level-order traversal can also compute depth.

---

## Related Problems

- Minimum Depth of Binary Tree
- Balanced Binary Tree
- Diameter of Binary Tree
