# Problem: Evaluate Reverse Polish Notation

## Problem Statement

Evaluate the value of an arithmetic expression in **Reverse Polish Notation (RPN)**.

Valid operators are:

```
+, -, *, /
```

Each operand may be an integer or another expression.

Division between two integers should truncate toward zero.

---

## Example

### Example 1

Input

```
tokens = ["2","1","+","3","*"]
```

Output

```
9
```

Explanation

```
((2 + 1) * 3) = 9
```

---

### Example 2

Input

```
tokens = ["4","13","5","/","+"]
```

Output

```
6
```

Explanation

```
4 + (13 / 5) = 6
```

---

### Example 3

Input

```
tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
```

Output

```
22
```

---

## Approach

Reverse Polish Notation expressions can be evaluated using a **Stack**.

### Key Idea

- Push numbers onto the stack.
- When an operator is encountered:
  - Pop the top two numbers from the stack.
  - Apply the operator.
  - Push the result back onto the stack.

### Algorithm

1. Traverse each token in the input array.
2. If the token is a number → push it onto the stack.
3. If the token is an operator:
   - Pop the top two elements.
   - Perform the operation.
   - Push the result back.
4. At the end, the stack will contain the final result.

---

## Time Complexity

```
O(n)
```

We process each token once.

---

## Space Complexity

```
O(n)
```

The stack may store all operands.

---

## C++ Implementation

```cpp
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens) {

    stack<int> st;

    for(string token : tokens){

        if(token == "+" || token == "-" || token == "*" || token == "/"){

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if(token == "+") st.push(a + b);
            else if(token == "-") st.push(a - b);
            else if(token == "*") st.push(a * b);
            else st.push(a / b);
        }
        else{
            st.push(stoi(token));
        }
    }

    return st.top();
}
```

---

## Key Takeaways

- Reverse Polish Notation removes the need for parentheses.
- Stack is the perfect data structure for evaluating postfix expressions.
- Commonly used in:
  - Expression evaluation
  - Compilers
  - Calculators
