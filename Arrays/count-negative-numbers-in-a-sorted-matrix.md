# Problem: Count Negative Numbers in a Sorted Matrix

## Problem Statement

Given a `m x n` matrix `grid` which is sorted in **non-increasing order** both row-wise and column-wise, return the number of **negative numbers** in the matrix.

---

## Example

### Example 1

Input
```
grid = [[4,3,2,-1],
        [3,2,1,-1],
        [1,1,-1,-2],
        [-1,-1,-2,-3]]
```

Output
```
8
```

---

### Example 2

Input
```
grid = [[3,2],
        [1,0]]
```

Output
```
0
```

---

## Approach: Top-Right Traversal (Two Pointer)

### Key Idea

Since the matrix is sorted both **row-wise and column-wise**, we start from the **top-right corner**.

- If the element is negative → all elements below it are also negative.
- If the element is positive → move down.

This reduces time complexity from **O(m × n)** to **O(m + n)**.

---

## Algorithm

1. Start from top-right corner.
2. If element < 0:
   - Add `(m - row)` to count.
   - Move left.
3. Else:
   - Move down.
4. Repeat until out of bounds.

---

## Time Complexity

```
O(m + n)
```

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
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int row = 0;
        int col = n - 1;
        int count = 0;
        
        while(row < m && col >= 0) {
            if(grid[row][col] < 0) {
                count += (m - row);
                col--;
            } else {
                row++;
            }
        }
        
        return count;
    }
};
```

---

## Key Takeaways

- Use matrix sorted property.
- Start traversal from top-right.
- Optimized approach better than brute force.

---

## Related Problems

- Search in 2D Matrix
- Spiral Matrix
- Rotate Matrix
