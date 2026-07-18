/*
Problem: Kth Largest Element in an Array
Platform: LeetCode
Pattern: Heap (Min Heap)
Folder: 18_Heap
Difficulty: Medium

Problem Statement:
Given an integer array nums and an integer k,
return the kth largest element in the array.

Note:
It is the kth largest element in sorted order,
not the kth distinct element.

Approach:
1. Maintain a Min Heap of size k.
2. Insert every element into the heap.
3. If heap size exceeds k:
   - Remove the smallest element.
4. After processing all elements,
   the top of the Min Heap is the kth largest element.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,
                       vector<int>,
                       greater<int>> pq;

        for(int i = 0; i < nums.size(); i++) {

            pq.push(nums[i]);

            if(pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};

/*
Key Learning:
1. Use a Min Heap to keep track of the k largest elements.
2. Heap size never exceeds k.
3. Top of the Min Heap is the kth largest element.
4. Efficient Top-K pattern using heaps.
*/
