/*
Problem: Reverse Linked List II
Platform: LeetCode
Pattern: Linked List (In-place Sublist Reversal)
Folder: 05_Linked_List
Difficulty: Medium

Problem Statement:
Given the head of a singly linked list and two integers left and right,
reverse the nodes from position left to right.

Return the modified list.

Approach:
1. Use dummy node to handle edge cases.
2. Move prev pointer to node before 'left'.
3. Reverse nodes one by one using head insertion technique.
4. Connect reversed part back to list.

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Step 1: Move prev to node before 'left'
        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse sublist
        ListNode* curr = prev->next;

        for(int i = 1; i <= right - left; i++) {
            ListNode* next = curr->next;

            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};

/*
Key Learning:
1. Dummy node simplifies edge cases.
2. Head insertion technique for sublist reversal.
3. No need to reverse entire list.
4. Important linked list manipulation pattern.
*/
