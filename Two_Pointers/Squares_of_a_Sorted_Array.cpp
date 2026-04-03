/*
Problem: Squares of a Sorted Array
Platform: LeetCode
Pattern: Two Pointers
Difficulty: Easy

Problem Statement:
Given an integer array nums sorted in non-decreasing order, return an array of 
the squares of each number sorted in non-decreasing order.

Approach:
Since the array is sorted, the largest square value can come from either
the leftmost negative number or the rightmost positive number.
We use two pointers:
- left at start
- right at end
We compare squares and fill the result array from the back.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int left = 0;
        int right = n - 1;
        int index = n - 1;
        
        while(left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            if(leftSquare > rightSquare) {
                ans[index] = leftSquare;
                left++;
            } else {
                ans[index] = rightSquare;
                right--;
            }
            
            index--;
        }
        
        return ans;
    }
};

/*
Key Learning:
1. Two pointers can be used when largest/smallest element is at ends.
2. Fill result array from back to maintain sorted order.
3. Useful when negative numbers are involved in sorted arrays.
*/
