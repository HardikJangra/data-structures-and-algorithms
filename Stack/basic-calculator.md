# Problem: Basic Calculator

## Problem Statement

Given a string `s` representing a valid arithmetic expression, implement a basic calculator to evaluate it.

The expression contains:

```
+, -, (, ), digits, and spaces
```

You are **not allowed** to use any built-in evaluation functions.

---

## Example

### Example 1

Input

```
s = "1 + 1"
```

Output

```
2
```

---

### Example 2

Input

```
s = " 2-1 + 2 "
```

Output

```
3
```

---

### Example 3

Input

```
s = "(1+(4+5+2)-3)+(6+8)"
```

Output

```
23
```

---

## Approach

We solve this problem using a **Stack** to handle parentheses.

### Key Idea

- Maintain a running **result**.
- Maintain a **sign** for addition or subtraction.
- When encountering `"("`, push the current result and sign onto the stack.
- When encountering `")"`, resolve the sub-expression using values from the stack.

### Algorithm

1. Traverse the string.
2. If the character is a digit → build the number.
3. If the character is `+` or `-` → update the sign.
4. If `"("` → push current result and sign onto stack.
5. If `")"` → pop sign and previous result from stack and update result.

---

## Time Complexity

```
O(n)
```

We traverse the expression once.

---

## Space Complexity

```
O(n)
```

For storing intermediate results in the stack.

---

## C++ Implementation

```cpp
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {

        stack<int> st;
        int result = 0;
        int number = 0;
        int sign = 1;

        for(char c : s){

            if(isdigit(c)){
                number = number * 10 + (c - '0');
            }

            else if(c == '+'){
                result += sign * number;
                number = 0;
                sign = 1;
            }

            else if(c == '-'){
                result += sign * number;
                number = 0;
                sign = -1;
            }

            else if(c == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }

            else if(c == ')'){
                result += sign * number;
                number = 0;

                result *= st.top();
                st.pop();

                result += st.top();
                st.pop();
            }
        }

        result += sign * number;

        return result;
    }
};
```

---

## Key Takeaways

- Stack helps handle nested parentheses.
- Expressions can be evaluated by maintaining a running result.
- Similar problems include:
  - Basic Calculator II
  - Evaluate Reverse Polish Notation
  - Expression Evaluation
