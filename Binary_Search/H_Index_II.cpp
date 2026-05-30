/*
Problem: H-Index II
Platform: LeetCode
Pattern: Binary Search
Folder: 13_Binary_Search
Difficulty: Medium

Problem Statement:
Given an array citations sorted in ascending order,
return the researcher's h-index.

The h-index is defined as:
A researcher has index h if h papers have at least h citations each.

Approach:
1. Since citations array is sorted,
   use binary search on indices.
2. At index mid:
   papers with at least citations[mid] citations
   = n - mid.
3. Compare:
   citations[mid] with (n - mid)
4. If equal:
   return h-index directly.
5. Otherwise search appropriate half.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {

        int low = 0;
        int high = citations.size() - 1;
        int n = citations.size();

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(citations[mid] == n - mid) {
                return n - mid;
            }
            else if(citations[mid] < n - mid) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return n - low;
    }
};

/*
Key Learning:
1. Binary search can be applied on mathematical conditions.
2. n - mid represents papers having at least citations[mid] citations.
3. Search for boundary where:
   citations[mid] >= n - mid
4. Elegant logarithmic solution using sorted input.
*/
