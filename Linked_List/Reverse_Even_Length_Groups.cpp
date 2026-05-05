/*
Problem: Reverse Nodes in Even Length Groups
Platform: LeetCode
Pattern: Linked List (Group Processing + Conditional Reversal)
Folder: 05_Linked_List
Difficulty: Medium

Problem Statement:
Given the head of a linked list, the nodes are arranged in groups of size 1, 2, 3, ...
Reverse the nodes in each group if the group has even length.

Return the modified list.

Approach:
1. Traverse the list in groups of increasing size.
2. Count actual group size (may be smaller at end).
3. If group size is even → reverse that group.
4. Else → keep as is.
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        int groupSize = 1;

        while(curr) {
            ListNode* groupStart = curr;
            int count = 0;

            // Count group size
            while(curr && count < groupSize) {
                curr = curr->next;
                count++;
            }

            // Reverse if even length
            if(count % 2 == 0) {
                ListNode* nextGroup = curr;
                ListNode* prevNode = nextGroup;
                ListNode* node = groupStart;

                while(node != nextGroup) {
                    ListNode* temp = node->next;
                    node->next = prevNode;
                    prevNode = node;
                    node = temp;
                }

                prev->next = prevNode;
                prev = groupStart;
            }
            else {
                for(int i = 0; i < count; i++) {
                    prev = prev->next;
                }
            }

            groupSize++;
        }

        return dummy->next;
    }
};

/*
Key Learning:
1. Dynamic group sizes (1,2,3,...).
2. Conditional reversal based on group length.
3. Combination of traversal + reversal logic.
4. Advanced linked list manipulation.
*/
