# Problem: Next Greater Element I

## Problem Statement

You are given two arrays `nums1` and `nums2` where `nums1` is a subset of `nums2`.

For each element in `nums1`, find the **next greater element** in `nums2`.

The **next greater element** of an element `x` in `nums2` is the first greater element to its **right**.

If it does not exist, return `-1`.

---

## Example

### Input

```
nums1 = [4,1,2]
nums2 = [1,3,4,2]
```

### Output

```
[-1,3,-1]
```

### Explanation

- Next greater element for **4** → none → `-1`
- Next greater element for **1** → `3`
- Next greater element for **2** → none → `-1`

---

### Example 2

```
nums1 = [2,4]
nums2 = [1,2,3,4]
```

Output:

```
[3,-1]
```

---

## Approach

This problem can be efficiently solved using a **Monotonic Stack**.

### Key Idea

We process `nums2` and maintain a stack that stores elements in **decreasing order**.

Steps:

1. Traverse `nums2`.
2. While the stack is not empty and the current element is greater than the top of the stack:
   - The current element becomes the **next greater element** for the stack top.
3. Store this mapping in a hash map.
4. Push the current element into the stack.
5. For elements left in the stack, no greater element exists → map them to `-1`.
6. Finally, construct the answer for elements in `nums1`.

This allows us to solve the problem in **linear time**.

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

For the stack and hashmap.

---

## C++ Implementation

```cpp
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    stack<int> st;
    unordered_map<int,int> mp;

    for(int num : nums2){

        while(!st.empty() && num > st.top()){
            mp[st.top()] = num;
            st.pop();
        }

        st.push(num);
    }

    while(!st.empty()){
        mp[st.top()] = -1;
        st.pop();
    }

    vector<int> ans;

    for(int num : nums1){
        ans.push_back(mp[num]);
    }

    return ans;
}
```

---

## Key Takeaways

- This problem introduces the concept of a **Monotonic Stack**.
- A monotonic stack helps solve problems involving **next greater/smaller elements** efficiently.
- Similar problems include:
  - Daily Temperatures
  - Stock Span
  - Largest Rectangle in Histogram

---
