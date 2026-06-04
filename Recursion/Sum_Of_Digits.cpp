/*
Problem: Sum Of Digits
Platform: GeeksforGeeks
Pattern: Recursion
Folder: 15_Recursion
Difficulty: Easy

Problem Statement:
Given a positive integer n,
find the sum of its digits using recursion.

Example:
Input: 1234
Output: 10

Explanation:
1 + 2 + 3 + 4 = 10

Approach:
1. Extract last digit using n % 10.
2. Recursively process remaining number using n / 10.
3. Add current digit to recursive result.
4. Base case:
   - n == 0

Time Complexity: O(d)
Space Complexity: O(d)

where d = number of digits
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int sumOfDigits(int n) {

        if(n == 0) {
            return 0;
        }

        return (n % 10) + sumOfDigits(n / 10);
    }
};

/*
Key Learning:
1. Break number into:
   - Last digit (n % 10)
   - Remaining number (n / 10)
2. Recursive processing of digits.
3. Very common number recursion pattern.
4. Foundation for many digit-based recursive problems.
*/
