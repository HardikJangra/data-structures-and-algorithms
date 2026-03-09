# Problem: Valid Parentheses

## Problem Statement

Given a string `s` containing just the characters:

```
'(', ')', '{', '}', '[' and ']'
```

Determine if the input string is valid.

A string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every closing bracket must have a corresponding opening bracket.

---

## Example

### Example 1

Input:
```
s = "()"
```

Output:
```
true
```

---

### Example 2

Input:
```
s = "()[]{}"
```

Output:
```
true
```

---

### Example 3

Input:
```
s = "(]"
```

Output:
```
false
```

---

## Approach

This problem can be solved using a **Stack data structure**.

### Key Idea

A stack follows **LIFO (Last In First Out)**.

We push opening brackets onto the stack and when we encounter a closing bracket, we check if it matches the top element of the stack.

### Algorithm

1. Create an empty stack.
2. Traverse each character of the string.
3. If the character is an opening bracket `(`, `{`, `[`, push it onto the stack.
4. If the character is a closing bracket:
   - If the stack is empty → return `false`.
   - Check if the top of the stack matches the corresponding opening bracket.
   - If it matches → pop the stack.
   - Otherwise → return `false`.
5. After traversal, if the stack is empty → return `true`, else `false`.

---

## Time Complexity

```
O(n)
```

We traverse the string once.

---

## Space Complexity

```
O(n)
```

In the worst case, the stack stores all opening brackets.

---

## C++ Implementation

```cpp
#include <stack>
using namespace std;

bool isValid(string s) {

    stack<char> st;

    for(char c : s) {

        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {

            if(st.empty())
                return false;

            char top = st.top();
            st.pop();

            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty();
}
```

---

## Key Takeaways

- This problem demonstrates the use of **Stack for matching pairs**.
- Stacks are commonly used in problems involving:
  - parentheses validation
  - expression evaluation
  - backtracking
- Always check **stack empty condition before popping**.
