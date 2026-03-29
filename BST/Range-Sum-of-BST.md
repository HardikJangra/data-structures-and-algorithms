# Problem: Range Sum of BST

## Problem Statement

Given the `root` node of a Binary Search Tree (BST) and two integers `low` and `high`, return the **sum of values** of all nodes with a value in the inclusive range `[low, high]`.

---

## Example

### Example 1

Input

```
root = [10,5,15,3,7,null,18]
low = 7
high = 15
```

Tree

```
        10
       /  \
      5    15
     / \     \
    3   7     18
```

Output

```
32
```

Explanation

Nodes in range `[7, 15]` are:

```
7 + 10 + 15 = 32
```

---

## Approach: DFS using Stack (Iterative)

### Key Idea

Since this is a **Binary Search Tree**, we can skip unnecessary nodes:

- If `node->val > low` → explore left subtree
- If `node->val < high` → explore right subtree

This reduces unnecessary traversal.

---

## Steps

1. Use a stack for DFS traversal.
2. If node value is in range → add to sum.
3. If node value > low → go left.
4. If node value < high → go right.
5. Continue until stack is empty.

---

## Time Complexity

```
O(n)
```

In worst case we visit all nodes.

Optimized due to BST pruning.

---

## Space Complexity

```
O(h)
```

Where `h` is height of tree.

---

## C++ Implementation

```cpp
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> st;
        st.push(root);
        int sum = 0;

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if (node == NULL) continue;

            if (node->val >= low && node->val <= high)
                sum += node->val;

            if (node->val > low)
                st.push(node->left);

            if (node->val < high)
                st.push(node->right);
        }

        return sum;
    }
};
```

---

## Key Takeaways

- Use **BST property to prune search space**.
- DFS traversal using stack.
- Avoid visiting unnecessary nodes.

---

## Related Problems

- Validate Binary Search Tree
- Trim BST
- Insert into BST
- Kth Smallest Element in BST
