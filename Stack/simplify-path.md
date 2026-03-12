# Problem: Simplify Path

## Problem Statement

Given a string `path`, which is an **absolute path** for a Unix-style file system, convert it to the **simplified canonical path**.

In Unix-style file systems:

- `"."` refers to the **current directory**.
- `".."` refers to the **parent directory**.
- Multiple consecutive slashes `"//"` are treated as a single slash.

The canonical path should:

- Start with a single `/`
- Have directories separated by a single `/`
- Not end with `/` unless it is the root directory

---

## Example

### Example 1

Input

```
path = "/home/"
```

Output

```
"/home"
```

---

### Example 2

Input

```
path = "/../"
```

Output

```
"/"
```

Explanation

Going above the root directory is not possible.

---

### Example 3

Input

```
path = "/home//foo/"
```

Output

```
"/home/foo"
```

---

### Example 4

Input

```
path = "/a/./b/../../c/"
```

Output

```
"/c"
```

---

## Approach

We use a **Stack** to keep track of valid directory names.

### Steps

1. Split the path using `/` as delimiter.
2. Traverse each directory name:
   - If the name is `"."` → ignore it.
   - If the name is `".."` → pop from stack (go to parent directory).
   - If it is a valid directory name → push it onto the stack.
3. Construct the final path from stack elements.

---

## Time Complexity

```
O(n)
```

Where `n` is the length of the path string.

---

## Space Complexity

```
O(n)
```

For storing directory names in the stack.

---

## C++ Implementation

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string temp;

        for (int i = 0; i <= path.size(); i++) {
            
            if (i == path.size() || path[i] == '/') {

                if (temp == "" || temp == ".") {
                    // ignore current directory
                }
                else if (temp == "..") {
                    // go to parent directory
                    if (!st.empty())
                        st.pop();
                }
                else {
                    // push valid directory name
                    st.push(temp);
                }

                temp = "";
            }
            else {
                temp += path[i];
            }
        }

        if (st.empty())
            return "/";

        string result = "";

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result;
    }
};
```

---

## Key Takeaways

- Stack is useful for handling hierarchical structures like file paths.
- `".."` removes the last directory from the path.
- `"."` represents the current directory and can be ignored.
- This problem demonstrates real-world use of stacks in **filesystem navigation**.

---
