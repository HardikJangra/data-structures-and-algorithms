/*
Problem: Reverse Linked List
Platform: LeetCode
Pattern: Linked List (Iterative Reversal)
Folder: 05_Linked_List
Difficulty: Easy

Problem Statement:
Given the head of a singly linked list, reverse the list
and return the new head.

Approach:
1. Use three pointers:
   - prev → previous node
   - curr → current node
   - next → next node
2. Reverse link:
   curr->next = prev
3. Move all pointers forward.

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

/*
Key Learning:
1. Classic 3-pointer technique.
2. Reverse pointers one by one.
3. In-place reversal (O(1) space).
4. Base for many linked list problems.
*/
