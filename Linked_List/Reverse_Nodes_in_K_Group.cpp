/*
Problem: Reverse Nodes in K-Group
Platform: LeetCode
Pattern: Linked List (Group Reversal)
Folder: 05_Linked_List
Difficulty: Hard

Problem Statement:
Given the head of a linked list, reverse the nodes of the list k at a time,
and return the modified list.

If the number of nodes is not a multiple of k,
the remaining nodes should remain as it is.

Approach:
1. Use dummy node to handle edge cases.
2. Find kth node from current group start.
3. Reverse nodes in group.
4. Connect reversed group back.
5. Move to next group.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;

        while(true) {
            // Step 1: Find kth node
            ListNode* kth = prevGroupEnd;
            for(int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            if(kth == NULL) break;

            // Step 2: Identify group boundaries
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            // Step 3: Reverse group
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;

            while(curr != nextGroupStart) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Step 4: Connect
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};

/*
Key Learning:
1. Extend reverse linked list to groups of size k.
2. Always find kth node before reversing.
3. Carefully reconnect reversed segments.
4. Very important advanced linked list problem.
*/
