/*
Problem: Peak Index In Mountain Array
Platform: LeetCode
Pattern: Binary Search
Folder: 13_Binary_Search
Difficulty: Medium

Problem Statement:
Given a mountain array arr,
return the index of the peak element.

A mountain array:
- strictly increases
- then strictly decreases

Approach:
1. Use binary search on slope direction.
2. If arr[mid] > arr[mid + 1]:
   - Peak lies on left side (including mid)
3. Else:
   - Peak lies on right side
4. Continue until low == high.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int low = 0;
        int high = arr.size() - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(arr[mid] > arr[mid + 1]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return high;
    }
};

/*
Key Learning:
1. Binary search can work on answer space / patterns.
2. Use neighboring elements to detect slope.
3. Increasing slope → move right.
4. Decreasing slope → move left.
*/
