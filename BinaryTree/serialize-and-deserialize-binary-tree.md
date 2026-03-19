# Problem: Serialize and Deserialize Binary Tree

## Problem Statement

Design an algorithm to **serialize** and **deserialize** a binary tree.

- **Serialize**: Convert a binary tree into a string.
- **Deserialize**: Convert the string back into the original binary tree.

You can design the format yourself.

---

## Example

Input Tree

```
        1
       / \
      2   3
         / \
        4   5
```

Serialized Output

```
"1,2,null,null,3,4,null,null,5,null,null,"
```

---

## Approach: DFS (Preorder Traversal)

### Key Idea

We use **preorder traversal**:

```
Root → Left → Right
```

- For null nodes, we store `"null"`
- Values are separated using `,`

This ensures we can reconstruct the tree exactly.

---

## Serialization

### Steps

1. Traverse tree using preorder.
2. Append node value to string.
3. If node is NULL → append `"null"`.

---

## Deserialization

### Steps

1. Split string into tokens.
2. Store tokens in a queue.
3. Rebuild tree recursively:
   - If value is `"null"` → return NULL
   - Otherwise create node
   - Build left subtree
   - Build right subtree

---

## Time Complexity

```
O(n)
```

Each node is processed once.

---

## Space Complexity

```
O(n)
```

For storing serialized data and recursion stack.

---

## C++ Implementation

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializeHelper(TreeNode* root, string &s) {
        if(root == NULL) {
            s += "null,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root, s);
        return s;
    }


    TreeNode* deserializeHelper(queue<string> &q) {
        string val = q.front();
        q.pop();

        if(val == "null")
            return NULL;

        TreeNode* node = new TreeNode(stoi(val));

        node->left = deserializeHelper(q);
        node->right = deserializeHelper(q);

        return node;
    }

    TreeNode* deserialize(string data) {

        queue<string> q;
        string temp = "";

        for(char c : data) {
            if(c == ',') {
                q.push(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        return deserializeHelper(q);
    }
};
```

---

## Key Takeaways

- Preorder traversal + null markers ensures full tree reconstruction.
- Queue helps maintain order during deserialization.
- This is a classic example of:
  👉 **Tree → String → Tree conversion**

---

## Related Problems

- Construct Binary Tree from Preorder and Inorder
- Binary Tree Level Order Traversal
- Invert Binary Tree
