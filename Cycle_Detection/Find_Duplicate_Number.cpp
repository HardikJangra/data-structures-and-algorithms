/*
Problem: Find the Duplicate Number
Platform: LeetCode
Pattern: Floyd’s Cycle Detection (Tortoise and Hare)
Difficulty: Medium

Problem Statement:
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive,
there is only one repeated number in nums. Return this repeated number.

You must solve the problem without modifying the array and using only constant extra space.

Approach:
We treat the array like a linked list:
- Each index points to nums[index]
- This forms a cycle because duplicate creates a loop

Steps:
1. Use slow and fast pointers to detect cycle.
2. Once they meet, reset one pointer to start.
3. Move both one step at a time.
4. The meeting point is the duplicate number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // Step 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        // Step 2: Find entry point of cycle
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

/*
Key Learning:
1. Array can be treated as linked list.
2. Duplicate number creates a cycle.
3. Floyd’s algorithm works beyond linked lists.
4. No extra space and no modification required.
*/
