/*
Problem: Remove Nodes From Linked List
Platform: LeetCode
Pattern: Monotonic Stack + Linked List
Folder: 11_Stack
Difficulty: Medium

Problem Statement:
Given the head of a linked list, remove every node that has
a node with a greater value anywhere to its right side.

Return the modified linked list.

Approach:
1. Use a monotonic decreasing stack.
2. Traverse linked list:
   - Remove smaller elements from stack.
   - Push current node.
3. Rebuild linked list from remaining stack nodes.

Time Complexity: O(n)
Space Complexity: O(n)
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        ListNode* temp = head;

        while(temp) {

            while(!st.empty() && st.top()->val < temp->val) {
                st.pop();
            }

            st.push(temp);
            temp = temp->next;
        }

        // Rebuild linked list
        ListNode* newHead = nullptr;

        while(!st.empty()) {
            ListNode* node = st.top();
            st.pop();

            node->next = newHead;
            newHead = node;
        }

        return newHead;
    }
};

/*
Key Learning:
1. Monotonic decreasing stack keeps only useful nodes.
2. Remove nodes having greater value on right.
3. Stack + linked list combination problem.
4. Similar concept to Next Greater Element.
*/
