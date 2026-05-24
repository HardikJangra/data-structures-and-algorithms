/*
Problem: Count Frequency In Sorted Array
Platform: GeeksforGeeks
Pattern: Binary Search
Folder: 13_Binary_Search
Difficulty: Easy

Problem Statement:
Given a sorted array arr[] and a target element,
find the number of occurrences of the target.

Approach:
1. Find first occurrence using binary search.
2. Find last occurrence using binary search.
3. Frequency = lastIndex - firstIndex + 1
4. If target not found → return 0.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int firstOccurrence(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(arr[mid] == target) {
                ans = mid;
                high = mid - 1;
            }
            else if(arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurrence(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(arr[mid] == target) {
                ans = mid;
                low = mid + 1;
            }
            else if(arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int countFreq(vector<int>& arr, int target) {

        int first = firstOccurrence(arr, target);

        if(first == -1)
            return 0;

        int last = lastOccurrence(arr, target);

        return last - first + 1;
    }
};

/*
Key Learning:
1. Frequency counting in sorted array using binary search.
2. Find left boundary and right boundary separately.
3. Avoid linear traversal.
4. Boundary binary search pattern.
*/
