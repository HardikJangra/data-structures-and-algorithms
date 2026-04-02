# Problem: Next Permutation

## Problem Statement

Implement the function **nextPermutation** which rearranges numbers into the **lexicographically next greater permutation** of numbers.

If such arrangement is not possible, it must rearrange it as the **lowest possible order (sorted in ascending order)**.

The replacement must be **in-place** and use only constant extra memory.

---

## Example

### Example 1

Input

```
nums = [1,2,3]
```

Output

```
[1,3,2]
```

---

### Example 2

Input

```
nums = [3,2,1]
```

Output

```
[1,2,3]
```

---

### Example 3

Input

```
nums = [1,1,5]
```

Output

```
[1,5,1]
```

---

## Approach

### Key Idea

We need to find the next lexicographically greater permutation.

Steps:

1. Find the **first decreasing element** from the right.
2. Find the element just **greater** than it on the right side.
3. Swap them.
4. Reverse the right part.

---

## Algorithm

1. Traverse from right and find index `i` such that:

```
nums[i] < nums[i+1]
```

2. If such index exists:
   - Find index `j` such that:

```
nums[j] > nums[i]
```

3. Swap `nums[i]` and `nums[j]`.
4. Reverse elements from `i+1` to end.

---

## Time Complexity

```
O(n)
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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }

        if(i >= 0){
            int j = n - 1;
            while(nums[j] <= nums[i]){
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
```

---

## Key Takeaways

- Important **permutation logic** problem.
- Used in many combinatorics problems.
- Pattern:
  - Find break point
  - Swap
  - Reverse

---

## Related Problems

- Permutations
- Permutations II
- Previous Permutation
