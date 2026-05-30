/*
Problem: Aggressive Cows
Platform: GeeksforGeeks
Pattern: Binary Search On Answer
Folder: 13_Binary_Search
Difficulty: Medium

Problem Statement:
Given positions of stalls and k cows,
place the cows in stalls such that the minimum
distance between any two cows is maximized.

Return the largest minimum distance possible.

Approach:
1. Sort stall positions.
2. Binary search on answer (minimum distance).
3. For a given distance:
   - Greedily place cows.
   - Check if at least k cows can be placed.
4. If possible:
   - Try larger distance.
5. Otherwise:
   - Reduce distance.

Time Complexity: O(n log(maxDistance))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canPlace(vector<int>& stalls,
                  int dist,
                  int k)
    {
        int cowPlaced = 1;
        int lastPlaced = stalls[0];

        for(int i = 1; i < stalls.size(); i++)
        {
            if(stalls[i] - lastPlaced >= dist)
            {
                cowPlaced++;
                lastPlaced = stalls[i];
            }
        }

        return cowPlaced >= k;
    }

    int aggressiveCows(vector<int> &stalls,
                       int k)
    {
        sort(stalls.begin(),
             stalls.end());

        int low = 1;
        int high =
        stalls.back() - stalls.front();

        int ans = 0;

        while(low <= high)
        {
            int mid =
            low + (high - low) / 2;

            if(canPlace(stalls, mid, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

/*
Key Learning:
1. Binary Search on Answer pattern.
2. Search for maximum valid answer.
3. Greedy placement used in validation function.
4. Classic interview problem.
*/
