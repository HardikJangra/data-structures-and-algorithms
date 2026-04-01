# Problem: Two Sum

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the **indices** of the two numbers such that they add up to the target.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

---

## Example

### Example 1

Input

```
nums = [2,7,11,15]
target = 9
```

Output

```
[0,1]
```

Explanation

```
nums[0] + nums[1] = 2 + 7 = 9
```

---

### Example 2

Input

```
nums = [3,2,4]
target = 6
```

Output

```
[1,2]
```

---

## Approach: Hash Map

### Key Idea

For each number, we check whether the **complement** exists in the hash map.

```
complement = target - nums[i]
```

If the complement already exists → we found the answer.

---

## Steps

1. Create a hash map to store number → index.
2. Traverse the array.
3. For each element:
   - Calculate complement.
   - If complement exists in map → return indices.
   - Otherwise store current number in map.

---

## Time Complexity

```
O(n)
```

We traverse the array once.

---

## Space Complexity

```
O(n)
```

For hash map.

---

## C++ Implementation

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()){
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
```

---

## Key Takeaways

- Use **Hash Map** to reduce time complexity from O(n²) → O(n).
- Very common interview question.
- Introduces concept of **complement search**.

---

## Related Problems

- Two Sum II (Sorted Array)
- 3Sum
- 4Sum
