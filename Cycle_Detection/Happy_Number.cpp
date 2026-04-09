/*
Problem: Happy Number
Platform: LeetCode
Pattern: Cycle Detection (HashSet)
Difficulty: Easy

Problem Statement:
Write an algorithm to determine if a number n is happy.

A happy number is defined by:
- Replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (happy),
  or it loops endlessly in a cycle (not happy).

Return true if n is a happy number, otherwise false.

Approach:
We use a HashSet to detect cycles.
- Keep calculating next number (sum of squares of digits).
- If we reach 1 → return true.
- If a number repeats → cycle detected → return false.

Time Complexity: O(log n)
Space Complexity: O(log n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNext(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1 && seen.find(n) == seen.end()){
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};

/*
Key Learning:
1. Detect cycles using HashSet.
2. Similar concept to linked list cycle detection.
3. Can also be solved using Floyd’s Cycle Detection (O(1) space).
4. Important for understanding cycle problems.
*/
