/*
Problem: Palindrome Linked List
Platform: LeetCode
Pattern: Fast & Slow Pointer + Reverse Linked List
Difficulty: Easy

Problem Statement:
Given the head of a singly linked list, return true if it is a palindrome 
or false otherwise.

Approach:
1. Use slow and fast pointers to find the middle of the linked list.
2. Reverse the second half of the list.
3. Compare first half and reversed second half.
4. If all values match → palindrome.

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* curr = slow;
        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compare both halves
        ListNode* left = head;
        ListNode* right = prev;

        while(right != NULL) {
            if(left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

/*
Key Learning:
1. Combine multiple patterns (slow-fast + reverse).
2. In-place reversal saves space.
3. Compare two halves efficiently.
4. Classic interview problem.
*/
