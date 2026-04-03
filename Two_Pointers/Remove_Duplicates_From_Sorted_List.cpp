/*
Problem: Remove Duplicates from Sorted List
Platform: LeetCode
Pattern: Linked List Traversal / Two Pointer
Difficulty: Easy

Problem Statement:
Given the head of a sorted linked list, delete all duplicates such that each element 
appears only once and return the linked list sorted as well.

Approach:
Since the linked list is sorted, duplicates will be adjacent.
We traverse the list using a pointer 'current'.
If current value equals next value, we skip the next node.
Otherwise, we move the current pointer forward.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        while(current != NULL && current->next != NULL) {
            if(current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        
        return head;
    }
};

/*
Key Learning:
1. Sorted linked list makes duplicate removal easy.
2. No extra space required (in-place).
3. Always check current and current->next.
4. This is a basic linked list traversal problem.
*/
