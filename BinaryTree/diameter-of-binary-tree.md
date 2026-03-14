# Problem: Diameter of Binary Tree

## Problem Statement

Given the `root` of a binary tree, return the **length of the diameter of the tree**.

The **diameter of a binary tree** is the length of the longest path between any two nodes in a tree.

This path may or may not pass through the root.

The length of a path between two nodes is represented by the **number of edges** between them.

---

## Example

### Example 1

Input

```
root = [1,2,3,4,5]
```

Tree representation

```
        1
       / \
      2   3
     / \
    4   5
```

Output

```
3
```

Explanation

The longest path is:

```
4 → 2 → 1 → 3
```

Number of edges = **3**

---

### Example 2

Input

```
root = [1,2]
```

Output

```
1
```

---

## Approach

This problem can be solved using **Depth First Search (DFS)**.

### Key Idea

The diameter at any node is:

```
left subtree height + right subtree height
```

So while computing the height of the tree, we also update the **maximum diameter**.

### Steps

1. Recursively calculate the height of the left subtree.
2. Recursively calculate the height of the right subtree.
3. Update the diameter using:

```
diameter = max(diameter, leftHeight + rightHeight)
```

4. Return the height of the current node:

```
1 + max(leftHeight, rightHeight)
```

---

## Time Complexity

```
O(n)
```

Each node is visited exactly once.

---

## Space Complexity

```
O(h)
```

Where `h` is the height of the tree due to recursion stack.

Worst case:

```
O(n)
```

(for skewed trees)

---

## C++ Implementation

```cpp
class Solution {
public:

    int diameter = 0;

    int height(TreeNode* root){

        if(root == NULL)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};
```

---

## Key Takeaways

- Diameter is calculated using **heights of left and right subtrees**.
- The longest path may or may not pass through the root.
- This problem combines **tree traversal and dynamic updates**.

---

## Related Problems

- Maximum Depth of Binary Tree
- Balanced Binary Tree
- Binary Tree Maximum Path Sum
