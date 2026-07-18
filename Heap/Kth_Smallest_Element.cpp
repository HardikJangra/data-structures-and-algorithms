/*
Problem: Kth Smallest Element
Platform: GeeksforGeeks
Pattern: Heap (Max Heap)
Folder: 18_Heap
Difficulty: Medium

Problem Statement:
Given an unsorted array arr[] and an integer k,
return the kth smallest element in the array.

Approach:
1. Maintain a Max Heap of size k.
2. Insert each element into the heap.
3. If heap size exceeds k:
   - Remove the largest element.
4. After processing all elements,
   the top of the heap is the kth smallest element.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {

        priority_queue<int> pq;

        for(int i = 0; i < arr.size(); i++) {

            pq.push(arr[i]);

            if(pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};

/*
Key Learning:
1. Use a Max Heap to keep track of the k smallest elements.
2. Heap size never exceeds k.
3. Top of the Max Heap is the kth smallest element.
4. More efficient than sorting when k is much smaller than n.
*/
