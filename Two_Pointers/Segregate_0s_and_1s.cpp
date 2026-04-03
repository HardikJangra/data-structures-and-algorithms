/*
Problem: Segregate 0s and 1s in an Array
Platform: GeeksforGeeks
Pattern: Two Pointers
Difficulty: Easy

Problem Statement:
You are given an array consisting of only 0s and 1s.
Your task is to segregate 0s and 1s in the array such that all 0s come before all 1s.
The segregation should be done in-place.

Approach:
We use Two Pointer approach:
Left pointer starts from the beginning.
Right pointer starts from the end.

- If left element is 0 → move left pointer forward.
- If right element is 1 → move right pointer backward.
- If left is 1 and right is 0 → swap both and move both pointers.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        while(left < right) {
            if(arr[left] == 0) {
                left++;
            }
            else if(arr[right] == 1) {
                right--;
            }
            else {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};

/*
Key Learning:
1. Two pointers help in partitioning arrays.
2. This is similar to partition step of Quick Sort.
3. In-place algorithm (no extra space).
4. Useful in Dutch National Flag type problems.
*/
