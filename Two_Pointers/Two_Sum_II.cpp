/*
Problem: Two Sum II - Input Array Is Sorted
Platform: LeetCode
Pattern: Two Pointers
Difficulty: Medium

Problem Statement:
Given a 1-indexed array of integers numbers that is sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1] and numbers[index2] where
1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers (1-indexed).

Approach:
Since the array is sorted, we use the Two Pointer approach.
We place one pointer at the beginning (left) and one at the end (right).
If the sum is too small, move left pointer forward.
If the sum is too large, move right pointer backward.
If sum equals target, return indices.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            
            if(sum == target) {
                return {left + 1, right + 1};
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return {};
    }
};

/*
Key Learning:
1. Two Pointer works when array is sorted.
2. Helps reduce time complexity from O(n^2) to O(n).
3. Use left++ when sum < target.
4. Use right-- when sum > target.
*/
