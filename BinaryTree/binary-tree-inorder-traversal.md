# Problem: Binary Tree Inorder Traversal

## Problem Statement

Given the root of a binary tree, return the **inorder traversal** of its nodes' values.

In **inorder traversal**, nodes are visited in the following order:

```
Left → Root → Right
```

---

## Example

### Example 1

Input

```
root = [1,null,2,3]
```

Tree representation

```
    1
     \
      2
     /
    3
```

Output

```
[1,3,2]
```

---

### Example 2

Input

```
root = []
```

Output

```
[]
```

---

### Example 3

Input

```
root = [1]
```

Output

```
[1]
```

---

## Approach

We perform **Inorder Traversal** of the binary tree.

The order of traversal is:

```
Left Subtree → Root Node → Right Subtree
```

### Two Approaches

1. **Recursive Traversal**
2. **Iterative Traversal using Stack**

---

## Recursive Approach

### Steps

1. Traverse the left subtree.
2. Visit the current node.
3. Traverse the right subtree.

---

## Time Complexity

```
O(n)
```

We visit each node exactly once.

---

## Space Complexity

```
O(n)
```

Due to recursion stack in the worst case.

---

## C++ Implementation (Recursive)

```cpp
class Solution {
public:

    void inorder(TreeNode* root, vector<int>& result){

        if(root == NULL)
            return;

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;

        inorder(root, result);

        return result;
    }
};
```

---

## Iterative Approach (Using Stack)

We simulate recursion using a **stack**.

### Steps

1. Push nodes while traversing the left subtree.
2. Pop the node and visit it.
3. Move to the right subtree.

---

## C++ Implementation (Iterative)

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(curr != NULL || !st.empty()){

            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            result.push_back(curr->val);

            curr = curr->right;
        }

        return result;
    }
};
```

---

## Key Takeaways

- Inorder traversal follows **Left → Root → Right**.
- In Binary Search Trees (BST), inorder traversal returns **sorted order**.
- Stack helps simulate recursion in the iterative approach.

---

## Related Problems

- Binary Tree Preorder Traversal
- Binary Tree Postorder Traversal
- Validate Binary Search Tree
