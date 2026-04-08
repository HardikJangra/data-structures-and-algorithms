/*
Problem: Linked List Cycle II (Find Start of Cycle)
Platform: LeetCode
Pattern: Fast & Slow Pointers (Floyd’s Algorithm)
Difficulty: Medium

Problem Statement:
Given the head of a linked list, return the node where the cycle begins.
If there is no cycle, return NULL.

Approach:
1. Use slow and fast pointers to detect cycle.
2. If they meet → cycle exists.
3. Move one pointer to head.
4. Move both pointers one step at a time.
5. The point where they meet again is the start of the cycle.

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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                
                // Step 2: Find starting point of cycle
                ListNode* ptr = head;

                while(ptr != slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }

                return ptr;
            }
        }

        return NULL;
    }
};

/*
Key Learning:
1. Floyd’s algorithm not only detects cycle but also finds its starting point.
2. Reset one pointer to head after detection.
3. Both pointers move at same speed to find cycle start.
4. Very frequently asked interview problem.
*/
