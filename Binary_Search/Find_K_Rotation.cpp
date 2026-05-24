/*
Problem: Find K Rotation
Platform: GeeksforGeeks
Pattern: Binary Search
Folder: 13_Binary_Search
Difficulty: Easy

Problem Statement:
Given a sorted and rotated array arr[],
find the number of times the array has been rotated.

Approach:
1. The index of minimum element equals
   the number of rotations.
2. Use binary search to find minimum element.
3. Compare middle element with high:
   - If arr[mid] > arr[high]:
       minimum lies in right half
   - Else:
       minimum lies in left half (including mid)

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &arr) {

        int low = 0;
        int high = arr.size() - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(arr[mid] > arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return high;
    }
};

/*
Key Learning:
1. Rotation count = index of minimum element.
2. Rotated sorted arrays retain partial ordering.
3. Binary search on unsorted half.
4. Extension of minimum-in-rotated-array problem.
*/
