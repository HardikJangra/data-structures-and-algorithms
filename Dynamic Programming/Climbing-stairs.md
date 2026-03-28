# Problem: Climbing Stairs

## Problem Statement

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb:

- 1 step
- 2 steps

In how many distinct ways can you climb to the top?

---

## Example

### Example 1

Input

```
n = 2
```

Output

```
2
```

Explanation

```
1 + 1
2
```

---

### Example 2

Input

```
n = 3
```

Output

```
3
```

Explanation

```
1 + 1 + 1
1 + 2
2 + 1
```

---

## Approach: Dynamic Programming (Memoization)

### Key Idea

To reach step `n`, you can come from:

```
n-1 step
n-2 step
```

So the recurrence relation becomes:

```
f(n) = f(n-1) + f(n-2)
```

This is the **Fibonacci pattern**.

---

## Steps

1. If `n <= 1`, return 1.
2. Use a DP array to store results.
3. Recursively compute using memoization.

---

## Time Complexity

```
O(n)
```

Each state is computed once.

---

## Space Complexity

```
O(n)
```

For DP array and recursion stack.

---

## C++ Implementation (Memoization)

```cpp
class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n <= 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
```

---

## Optimized Approach (Tabulation)

We can solve this iteratively.

### Time Complexity

```
O(n)
```

### Space Complexity

```
O(1)
```

---

## C++ Implementation (Space Optimized)

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;

        int prev2 = 1;
        int prev1 = 1;

        for(int i = 2; i <= n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
```

---

## Key Takeaways

- This is a **Fibonacci DP problem**.
- Can be solved using:
  - Recursion
  - Memoization
  - Tabulation
  - Space Optimization

---

## Related Problems

- Fibonacci Number
- Min Cost Climbing Stairs
- House Robber
