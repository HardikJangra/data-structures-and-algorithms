# Problem: Delete Node in a Binary Search Tree

## Problem Statement

Given a root node reference of a Binary Search Tree (BST) and a key, delete the node with the given key in the BST and return the root node.

The deletion should maintain the BST property.

---

## Example

### Example 1

Input

```
root = [5,3,6,2,4,null,7]
key = 3
```

Tree before deletion

```
        5
       / \
      3   6
     / \   \
    2   4   7
```

Tree after deletion

```
        5
       / \
      4   6
     /     \
    2       7
```

---

## Approach

To delete a node in BST, there are **3 cases**:

### Case 1: Node is a leaf (no children)

Simply delete the node.

### Case 2: Node has one child

Replace the node with its child.

### Case 3: Node has two children

- Find the **inorder successor** (smallest value in right subtree).
- Replace node value with successor value.
- Delete the successor node.

---

## Steps

1. Search for the node to delete.
2. If found:
   - Handle 3 deletion cases.
3. Return updated root.

---

## Time Complexity

```
O(h)
```

Where `h` is height of BST.

- Balanced BST → `O(log n)`
- Skewed BST → `O(n)`

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
    TreeNode* findMin(TreeNode* root){
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            // Case 1: No child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            // Case 2: One child
            else if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            else {
                TreeNode* succ = findMin(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }

        return root;
    }
};
```

---

## Key Takeaways

- Deletion in BST has **3 cases**.
- For two children, use **inorder successor**.
- Maintain BST property after deletion.

---

## Related Problems

- Insert into BST
- Search in BST
- Validate BST
- Lowest Common Ancestor in BST
