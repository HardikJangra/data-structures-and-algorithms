# Problem: Self Dividing Numbers

## Problem Statement

A **self-dividing number** is a number that is divisible by every digit it contains.

For example:

```
128 is a self-dividing number because:
128 % 1 == 0
128 % 2 == 0
128 % 8 == 0
```

Given two integers `left` and `right`, return a list of all the **self-dividing numbers** in the range `[left, right]`.

---

## Example

### Example 1

Input

```
left = 1
right = 22
```

Output

```
[1,2,3,4,5,6,7,8,9,11,12,15,22]
```

---

## Approach

### Key Idea

For each number:

1. Extract digits one by one.
2. Check:
   - Digit should not be `0`
   - Number should be divisible by digit
3. If all digits satisfy condition → self-dividing number.

---

## Algorithm

1. Loop from `left` to `right`.
2. For each number:
   - Extract digits using `% 10`
   - Check divisibility
3. Store valid numbers in result vector.

---

## Time Complexity

```
O(n × d)
```

Where:
- `n` = range size
- `d` = number of digits

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
    bool isSelfDivisible(int num){
        int temp = num;

        while(temp > 0){
            int digit = temp % 10;

            if(digit == 0 || num % digit != 0){
                return false;
            }

            temp = temp / 10;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for(int i = left; i <= right; i++){
            if(isSelfDivisible(i)){
                result.push_back(i);
            }
        }

        return result;
    }
};
```

---

## Key Takeaways

- Use digit extraction using `% 10`.
- Avoid numbers containing `0`.
- Practice for number-based problems.

---

## Related Problems

- Count Digits
- Reverse Integer
- Palindrome Number
