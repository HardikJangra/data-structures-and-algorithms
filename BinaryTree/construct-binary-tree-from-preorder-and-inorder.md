# Problem: Construct Binary Tree from Preorder and Inorder Traversal

## Problem Statement

Given two integer arrays `preorder` and `inorder` where:

- `preorder` is the preorder traversal of a binary tree
- `inorder` is the inorder traversal of the same tree

Construct and return the binary tree.

---

## Example

### Example 1

Input

```
preorder = [3,9,20,15,7]
inorder  = [9,3,15,20,7]
```

Tree

```
        3
       / \
      9  20
         / \
        15  7
```

---

### Example 2

Input

```
preorder = [-1]
inorder  = [-1]
```

Output

```
[-1]
```

---

## Approach: DFS + Recursion

### Key Idea

- In **preorder**, the first element is always the **root**.
- In **inorder**, elements left of root belong to left subtree, and right belong to right subtree.

---

## Steps

1. Take current root from preorder using index.
2. Find root position in inorder array.
3. Split inorder into:
   - left subtree
   - right subtree
4. Recursively build left and right subtrees.

---

## Time Complexity

```
O(n²)
```

- For each node, we search in inorder array → O(n)

---

## Space Complexity

```
O(n)
```

For recursion stack.

---

## C++ Implementation

```cpp
class Solution {
public:
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if(start > end)
            return NULL;
        
        int rootVal = preorder[idx];
        int i = start;
        
        for(; i <= end; i++) {
            if(inorder[i] == rootVal)
                break;
        }
        
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left  = solve(preorder, inorder, start, i-1, idx);
        root->right = solve(preorder, inorder, i+1, end, idx);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        int idx = 0;
        
        return solve(preorder, inorder, 0, n-1, idx);
    }
};
```

---

## Key Takeaways

- Preorder gives **root first**.
- Inorder helps **split left and right subtree**.
- Recursive tree construction is a common pattern.

---

## Optimization (Important)

We can optimize this to **O(n)** using a hashmap:

- Store inorder indices in a map
- Avoid searching each time

---

## Related Problems

- Serialize and Deserialize Binary Tree
- Construct Binary Tree from Inorder and Postorder
- Binary Tree Traversals
