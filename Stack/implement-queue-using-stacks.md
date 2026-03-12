# Problem: Implement Queue using Stacks

## Problem Statement

Implement a **first in first out (FIFO) queue** using only two stacks.

The implemented queue should support the following operations:

- `push(x)` → Push element `x` to the back of the queue.
- `pop()` → Removes the element from the front of the queue.
- `peek()` → Get the front element.
- `empty()` → Returns whether the queue is empty.

You must use only standard stack operations.

---

## Example

### Input

```
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
```

### Output

```
[null, null, null, 1, 1, false]
```

### Explanation

```
MyQueue myQueue = new MyQueue();
myQueue.push(1); 
myQueue.push(2);
myQueue.peek(); // return 1
myQueue.pop();  // return 1
myQueue.empty(); // return false
```

---

## Approach

We use **two stacks**:

- `input stack` → used for pushing elements
- `output stack` → used for popping elements

### Key Idea

Queue follows **FIFO** while stack follows **LIFO**.

To simulate FIFO behavior:

1. Push all new elements into the **input stack**.
2. When popping or peeking:
   - If the output stack is empty:
     - Move all elements from input stack to output stack.
   - Then pop or peek from output stack.

This reverses the order and gives correct FIFO behavior.

---

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| push | O(1) |
| pop | Amortized O(1) |
| peek | Amortized O(1) |
| empty | O(1) |

---

## Space Complexity

```
O(n)
```

We store elements in two stacks.

---

## C++ Implementation

```cpp
#include <stack>
using namespace std;

class MyQueue {
public:

    stack<int> input;
    stack<int> output;

    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {

        if(output.empty()){

            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }

        }

        int val = output.top();
        output.pop();

        return val;
    }
    
    int peek() {

        if(output.empty()){

            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }

        }

        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};
```

---

## Key Takeaways

- This problem demonstrates how one data structure can simulate another.
- Two stacks help reverse the order of elements to mimic queue behavior.
- Amortized time complexity ensures operations remain efficient.

---
