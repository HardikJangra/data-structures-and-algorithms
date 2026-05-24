/*
Problem: Find Minimum In Rotated Sorted Array
Platform: LeetCode
Pattern: Binary Search
Folder: 13_Binary_Search
Difficulty: Medium

Problem Statement:
Suppose an array of unique integers is sorted in ascending order
and rotated between 1 and n times.

Return the minimum element in the array.

Approach:
1. Use binary search.
2. Compare middle element with high:
   - If nums[mid] > nums[high]:
       minimum lies in right half
   - Else:
       minimum lies in left half (including mid)
3. Continue until low == high.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};

/*
Key Learning:
1. Rotated sorted arrays still contain sorted structure.
2. Compare with high to identify unsorted half.
3. Minimum always lies in unsorted portion.
4. Important rotated-array binary search pattern.
*/
