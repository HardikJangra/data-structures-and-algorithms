# Problem: Min Stack

## Problem Statement

Design a stack that supports the following operations:

- `push(x)` → Push element `x` onto stack.
- `pop()` → Removes the element on top of the stack.
- `top()` → Get the top element.
- `getMin()` → Retrieve the minimum element in the stack.

All operations must run in **O(1) time complexity**.

---

## Example

### Input
```
["MinStack","push","push","push","getMin","pop","top","getMin"]

[[],[-2],[0],[-3],[],[],[],[]]
```

### Output
```
[null,null,null,null,-3,null,0,-2]
```

### Explanation

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

---

## Approach

To efficiently retrieve the minimum element in constant time, we use **two stacks**:

1. **Main Stack** → stores all elements.
2. **Min Stack** → keeps track of the minimum element at every stage.

### Steps

- When pushing an element:
  - Push it to the main stack.
  - If the min stack is empty or the element is smaller than the current minimum, push it to the min stack.

- When popping:
  - If the popped element equals the top of the min stack, pop from the min stack as well.

- `getMin()` simply returns the top element of the min stack.

This ensures all operations run in **O(1)** time.

---

## Time Complexity

| Operation | Complexity |
|--------|-------------|
| push | O(1) |
| pop | O(1) |
| top | O(1) |
| getMin | O(1) |

---

## Space Complexity

```
O(n)
```

Because we store elements in two stacks.

---

## C++ Implementation

```cpp
#include <stack>
using namespace std;

class MinStack {
public:

    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) {

        st.push(val);

        if(minSt.empty() || val <= minSt.top()){
            minSt.push(val);
        }
    }
    
    void pop() {

        if(st.top() == minSt.top()){
            minSt.pop();
        }

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
```

---

## Key Takeaways

- Using an auxiliary stack helps track the minimum element efficiently.
- This avoids scanning the entire stack to find the minimum.
- A common interview technique is **maintaining extra data structures for constant-time operations**.

---
