/*
Problem: Swap Nodes in Pairs
Platform: LeetCode
Pattern: Linked List (Pairwise Pointer Manipulation)
Folder: 05_Linked_List
Difficulty: Medium

Problem Statement:
Given a linked list, swap every two adjacent nodes
and return its head.

You must not modify values — only pointers.

Approach:
1. Use a dummy node to simplify edge cases.
2. For each pair:
   - first = prev->next
   - second = first->next
3. Rewire:
   prev -> second -> first -> nextPair
4. Move prev forward by 2 nodes.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while(prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev
            prev = first;
        }

        return dummy->next;
    }
};

/*
Key Learning:
1. Use dummy node for safe pointer handling.
2. Swap nodes without changing values.
3. Practice pointer rewiring.
4. Foundation for k-group reversal problems.
*/
