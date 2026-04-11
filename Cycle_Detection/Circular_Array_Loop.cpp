/*
Problem: Circular Array Loop
Platform: LeetCode
Pattern: Floyd’s Cycle Detection / Fast & Slow Pointer
Difficulty: Medium

Problem Statement:
You are given a circular integer array nums where each element indicates
the number of steps to move forward or backward.

Determine if there exists a cycle in the array such that:
1. Cycle length > 1
2. All movements in the cycle are in the same direction

Return true if such a cycle exists, else false.

Approach:
1. Treat array as circular linked list.
2. Use Floyd’s Cycle Detection for each index.
3. Ensure all elements in cycle move in same direction.
4. Reject self-loop (cycle length 1).

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNext(vector<int>& nums, int index) {
        int n = nums.size();
        return ((index + nums[index]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            bool direction = nums[i] > 0;

            int slow = i;
            int fast = i;

            while(true) {
                int nextSlow = getNext(nums, slow);
                if((nums[nextSlow] > 0) != direction) break;

                int nextFast = getNext(nums, fast);
                if((nums[nextFast] > 0) != direction) break;

                nextFast = getNext(nums, nextFast);
                if((nums[nextFast] > 0) != direction) break;

                slow = nextSlow;
                fast = nextFast;

                if(slow == fast) {
                    if(slow == getNext(nums, slow)) break; // self loop
                    return true;
                }
            }
        }

        return false;
    }
};

/*
Key Learning:
1. Array can simulate circular linked list.
2. Apply Floyd’s algorithm in circular structures.
3. Must validate direction consistency.
4. Reject cycle of length 1.
*/
