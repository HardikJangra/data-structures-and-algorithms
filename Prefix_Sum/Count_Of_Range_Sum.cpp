/*
Problem: Count of Range Sum
Platform: LeetCode
Pattern: Prefix Sum + Merge Sort (Divide & Conquer)
Folder: 09_Prefix_Sum
Difficulty: Hard

Problem Statement:
Given an integer array nums and two integers lower and upper,
return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) = nums[i] + ... + nums[j]

Approach:
1. Compute prefix sum array.
2. Reduce problem to:
   count pairs (i < j) such that:
   lower ≤ prefix[j] - prefix[i] ≤ upper

3. Use modified merge sort:
   - Divide prefix array
   - Count valid pairs across halves
   - Merge sorted halves

4. Use two pointers to count valid ranges efficiently.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n, lower, upper);
    }

    int mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if(left >= right) return 0;

        int mid = (left + right) / 2;
        int count = 0;

        count += mergeSort(prefix, left, mid, lower, upper);
        count += mergeSort(prefix, mid + 1, right, lower, upper);

        int j = mid + 1, k = mid + 1;

        for(int i = left; i <= mid; i++) {
            while(j <= right && prefix[j] - prefix[i] < lower) j++;
            while(k <= right && prefix[k] - prefix[i] <= upper) k++;

            count += (k - j);
        }

        // Merge step
        vector<long long> temp;
        int i = left;
        j = mid + 1;

        while(i <= mid && j <= right) {
            if(prefix[i] <= prefix[j]) temp.push_back(prefix[i++]);
            else temp.push_back(prefix[j++]);
        }

        while(i <= mid) temp.push_back(prefix[i++]);
        while(j <= right) temp.push_back(prefix[j++]);

        for(int i = left; i <= right; i++) {
            prefix[i] = temp[i - left];
        }

        return count;
    }
};

/*
Key Learning:
1. Transform range sum into prefix difference problem.
2. Use merge sort to count valid pairs efficiently.
3. Two-pointer technique inside merge step.
4. Important advanced pattern (Divide & Conquer + Prefix Sum).
*/
