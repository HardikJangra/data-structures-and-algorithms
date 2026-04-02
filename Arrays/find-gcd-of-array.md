# Problem: Find Greatest Common Divisor of Array

## Problem Statement

Given an integer array `nums`, return the **greatest common divisor (GCD)** of the smallest number and largest number in the array.

The **GCD** of two numbers is the largest positive integer that divides both numbers.

---

## Example

### Example 1

Input

```
nums = [2,5,6,9,10]
```

Output

```
2
```

Explanation

- Smallest number = 2
- Largest number = 10
- GCD(2, 10) = 2

---

### Example 2

Input

```
nums = [7,5,6,8,3]
```

Output

```
1
```

---

## Approach

### Key Idea

1. Find the **minimum** element in the array.
2. Find the **maximum** element in the array.
3. Compute **GCD(min, max)** using Euclidean Algorithm.

---

## Euclidean Algorithm

```
gcd(a, b) = gcd(b, a % b)
```

Repeat until `b = 0`.

---

## Time Complexity

```
O(n + log(min, max))
```

- O(n) to find min and max
- O(log n) for GCD

---

## Space Complexity

```
O(1)
```

---

## C++ Implementation

```cpp
class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < mini) {
                mini = nums[i];
            }
            if (nums[i] > maxi) {
                maxi = nums[i];
            }
        }

        return gcd(mini, maxi);
    }
};
```

---

## Key Takeaways

- Use **Euclidean Algorithm** for GCD.
- Only min and max are needed.

---

## Related Problems

- GCD of Strings
- LCM of Two Numbers
- Number Theory Problems
