/*
Problem: Koko Eating Bananas
Platform: LeetCode
Pattern: Binary Search On Answer
Folder: 13_Binary_Search
Difficulty: Medium

Problem Statement:
Koko loves eating bananas.
There are piles of bananas, and Koko can eat at most k bananas per hour.

Return the minimum integer eating speed k such that
Koko can finish all bananas within h hours.

Approach:
1. Binary search on possible eating speed.
2. Search space:
   - low = 1
   - high = maximum pile size
3. For each speed:
   - Calculate total hours required.
4. If possible within h hours:
   - Try smaller speed.
5. Else:
   - Increase speed.

Time Complexity: O(n log(maxPile))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canEatAll(vector<int>& piles,
                   int h,
                   int speed)
    {
        long long totalHours = 0;

        for(int pile : piles)
        {
            totalHours +=
            (pile + speed - 1) / speed;
        }

        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles,
                       int h)
    {
        int low = 1;

        int high =
        *max_element(piles.begin(),
                     piles.end());

        int ans = high;

        while(low <= high)
        {
            int mid =
            low + (high - low) / 2;

            if(canEatAll(piles, h, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

/*
Key Learning:
1. Binary search can be applied on answer space.
2. Search for minimum valid answer.
3. Use helper function to validate feasibility.
4. Very important interview pattern.
*/
