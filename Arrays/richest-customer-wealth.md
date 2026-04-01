# Problem: Richest Customer Wealth

## Problem Statement

You are given an `m x n` integer grid `accounts` where:

- `accounts[i][j]` is the amount of money the ith customer has in the jth bank.

Return the **wealth** that the richest customer has.

A customer's wealth is the sum of money they have in all their bank accounts.

---

## Example

### Example 1

Input

```
accounts = [[1,2,3],[3,2,1]]
```

Output

```
6
```

Explanation

- Customer 1 wealth = 1 + 2 + 3 = 6
- Customer 2 wealth = 3 + 2 + 1 = 6

So the richest wealth = 6.

---

### Example 2

Input

```
accounts = [[1,5],[7,3],[3,5]]
```

Output

```
10
```

---

## Approach

This problem is straightforward:

1. Traverse each customer (row).
2. Calculate sum of each row.
3. Track the maximum sum.

---

## Time Complexity

```
O(m × n)
```

Where:
- `m` = number of customers
- `n` = number of banks

---

## Space Complexity

```
O(1)
```

We use only variables for sum and max.

---

## C++ Implementation

```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        
        for(int i = 0; i < accounts.size(); i++) {
            int sum = 0;
            
            for(int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[i][j];
            }
            
            maxWealth = max(maxWealth, sum);
        }
        
        return maxWealth;
    }
};
```

---

## Key Takeaways

- Basic **2D array traversal** problem.
- Practice for matrix-based problems.

---

## Related Problems

- Matrix Diagonal Sum
- Row Sum
- Spiral Matrix
