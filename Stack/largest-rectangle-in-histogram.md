# Problem: Largest Rectangle in Histogram

## Problem Statement

Given an array of integers `heights` representing the height of bars in a histogram where the width of each bar is `1`, return the **area of the largest rectangle** that can be formed in the histogram.

---

## Example

### Example 1

Input

```
heights = [2,1,5,6,2,3]
```

Output

```
10
```

Explanation

The largest rectangle is formed using heights `[5,6]`.

```
height = 5
width = 2
area = 10
```

---

### Example 2

Input

```
heights = [2,4]
```

Output

```
4
```

---

## Approach

We solve this problem using **Monotonic Stack** along with the concept of:

- **Previous Smaller Element (PSE)**
- **Next Smaller Element (NSE)**

For every bar, we determine the **maximum width** it can extend while maintaining the same height.

### Steps

1. Find the **Previous Smaller Element** for each bar.
2. Find the **Next Smaller Element** for each bar.
3. The rectangle width for each bar is calculated as:

```
width = right[i] - left[i] - 1
```

4. Compute the area:

```
area = heights[i] * width
```

5. Track the **maximum area** among all bars.

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

Extra space is used for:
- left array
- right array
- stack

---

## C++ Implementation (Using Previous Smaller & Next Smaller Elements)

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element
        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller Element
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        int maxArea = 0;

        for(int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
```

---

## Key Takeaways

- This is a classic **Monotonic Stack problem**.
- Stack helps efficiently find **Previous Smaller Element (PSE)** and **Next Smaller Element (NSE)**.
- Instead of checking every possible rectangle (`O(n²)`), we solve it in **O(n)** time.

### Similar Problems

- Daily Temperatures
- Next Greater Element
- Stock Span Problem
- Maximal Rectangle
