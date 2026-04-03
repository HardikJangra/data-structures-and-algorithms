/*
Problem: Remove Duplicates from Sorted Array
Platform: LeetCode
Pattern: Two Pointers
Difficulty: Easy

Problem Statement:
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place 
such that each unique element appears only once. The relative order of the elements should 
be kept the same.

Return the number of unique elements in nums.

Approach:
We use Two Pointer approach:
Pointer i keeps track of the position of the last unique element.
Pointer j traverses the array.
If nums[j] != nums[i], we found a new unique element, so increment i and update nums[i].

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
    }
};

/*
Key Learning:
1. Two pointers can be used for in-place array modification.
2. i pointer tracks unique elements.
3. j pointer scans the array.
4. This is an in-place algorithm (no extra space used).
*/
