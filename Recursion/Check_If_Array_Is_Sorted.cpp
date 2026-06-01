/*
Problem: Check If Array Is Sorted
Platform: GeeksforGeeks
Pattern: Recursion
Folder: 15_Recursion
Difficulty: Easy

Problem Statement:
Given an array arr[],
check whether the array is sorted in non-decreasing order.

Return true if sorted, otherwise false.

Approach:
1. Compare current element with next element.
2. If current > next:
   - Array is not sorted.
3. Otherwise recursively check remaining array.
4. Base case:
   - Reached last element.

Time Complexity: O(n)
Space Complexity: O(n)
(Recursion stack)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(vector<int>& arr, int i) {

        if(i >= arr.size() - 1) {
            return true;
        }

        if(arr[i] > arr[i + 1]) {
            return false;
        }

        return solve(arr, i + 1);
    }

    bool isSorted(vector<int>& arr) {
        return solve(arr, 0);
    }
};

/*
Key Learning:
1. Break array problem into smaller subproblems.
2. Compare adjacent elements recursively.
3. Stop immediately when disorder is found.
4. Basic linear recursion pattern.
*/
