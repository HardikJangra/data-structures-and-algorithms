/*
Problem: Linked List Cycle
Platform: LeetCode
Pattern: Fast & Slow Pointers (Floyd’s Cycle Detection)
Difficulty: Easy

Problem Statement:
Given the head of a linked list, determine if the linked list has a cycle in it.
Return true if there is a cycle, otherwise return false.

Approach:
We use two pointers:
- slow pointer moves one step at a time
- fast pointer moves two steps at a time

If there is a cycle, both pointers will meet at some point.
If fast reaches NULL, then no cycle exists.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};

/*
Key Learning:
1. Floyd’s Cycle Detection Algorithm.
2. Fast pointer moves twice as fast as slow.
3. If cycle exists → pointers will meet.
4. No extra space required.
*/
