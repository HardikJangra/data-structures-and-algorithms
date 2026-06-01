/*
Problem: Fibonacci Number
Platform: LeetCode
Pattern: Recursion
Folder: 15_Recursion
Difficulty: Easy

Problem Statement:
The Fibonacci numbers are defined as:

F(0) = 0
F(1) = 1

F(n) = F(n-1) + F(n-2) for n > 1

Given n, return F(n).

Approach:
1. Define base cases:
   - fib(0) = 0
   - fib(1) = 1
2. Recursively compute:
   fib(n) = fib(n-1) + fib(n-2)

Time Complexity: O(2^n)
Space Complexity: O(n)
(Recursion stack)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {

        if(n == 0) {
            return 0;
        }

        if(n == 1) {
            return 1;
        }

        return fib(n - 1) + fib(n - 2);
    }
};

/*
Key Learning:
1. Classic recursion problem.
2. Every recursive problem needs:
   - Base Case
   - Recursive Relation
3. Demonstrates overlapping subproblems.
4. Motivation for Dynamic Programming.
*/
