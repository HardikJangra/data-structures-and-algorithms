/*
Problem: Reorder List
Platform: LeetCode
Pattern: Linked List (Find Middle + Reverse + Merge)
Difficulty: Medium

Problem Statement:
Given the head of a singly linked list L:
L0 → L1 → … → Ln-1 → Ln

Reorder it to:
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

You may not modify node values, only change pointers.

Approach:
1. Find the middle of the linked list using slow & fast pointers.
2. Reverse the second half of the list.
3. Merge the two halves alternately.

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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        while(second) {
            ListNode* nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }

        // Step 3: Merge both halves
        ListNode* first = head;
        ListNode* secondHalf = prev;

        while(secondHalf) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = secondHalf->next;

            first->next = secondHalf;
            secondHalf->next = temp1;

            first = temp1;
            secondHalf = temp2;
        }
    }
};

/*
Key Learning:
1. Combination of 3 techniques (middle + reverse + merge).
2. Very important pattern for linked list problems.
3. In-place modification without extra space.
4. Frequently asked in interviews.
*/
