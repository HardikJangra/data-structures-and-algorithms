# Problem: Daily Temperatures

## Problem Statement

Given an array of integers `temperatures` representing the daily temperatures, return an array `answer` such that:

`answer[i]` is the number of days you have to wait after day `i` to get a warmer temperature.

If there is no future day for which this is possible, keep `answer[i] = 0`.

---

## Example

### Example 1

Input

```
temperatures = [73,74,75,71,69,72,76,73]
```

Output

```
[1,1,4,2,1,1,0,0]
```

Explanation

- Day 0 → wait **1 day** to get warmer temperature.
- Day 1 → wait **1 day**.
- Day 2 → wait **4 days**.
- Day 3 → wait **2 days**.

---

### Example 2

Input

```
temperatures = [30,40,50,60]
```

Output

```
[1,1,1,0]
```

---

## Approach

This problem can be solved efficiently using a **Monotonic Stack**.

### Key Idea

We maintain a stack that stores **indices of temperatures** in decreasing order.

Steps:

1. Traverse the temperature array.
2. While the stack is not empty and the current temperature is greater than the temperature at the stack's top index:
   - Pop the index from the stack.
   - Calculate the number of days waited.
3. Store the result in the answer array.
4. Push the current index into the stack.

This ensures each element is pushed and popped at most once.

---

## Time Complexity

```
O(n)
```

Each element is pushed and popped from the stack at most once.

---

## Space Complexity

```
O(n)
```

For the stack and output array.

---

## C++ Implementation

```cpp
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {

    int n = temperatures.size();
    vector<int> ans(n,0);
    stack<int> st;

    for(int i = 0; i < n; i++){

        while(!st.empty() && temperatures[i] > temperatures[st.top()]){

            int index = st.top();
            st.pop();

            ans[index] = i - index;
        }

        st.push(i);
    }

    return ans;
}
```

---

## Key Takeaways

- This problem uses the **Monotonic Stack pattern**.
- Instead of storing values, we store **indices**.
- Similar problems include:
  - Next Greater Element
  - Stock Span Problem
  - Largest Rectangle in Histogram
