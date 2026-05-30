/*
Problem: Minimum Number Of Days To Make M Bouquets
Platform: LeetCode
Pattern: Binary Search On Answer
Folder: 13_Binary_Search
Difficulty: Medium

Problem Statement:
You are given an integer array bloomDay, an integer m,
and an integer k.

You need to make m bouquets.
To make one bouquet, you need k adjacent flowers.

Return the minimum number of days required to make m bouquets.
If impossible, return -1.

Approach:
1. Binary search on answer (days).
2. Search space:
   - low = minimum bloom day
   - high = maximum bloom day
3. For a given day:
   - Count how many bouquets can be formed.
4. If possible:
   - Try smaller day.
5. Otherwise:
   - Increase day.

Time Complexity: O(n log(maxBloomDay))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canMake(vector<int>& bloomDay,
                 int day,
                 int m,
                 int k)
    {
        int bouquet = 0;
        int flowers = 0;

        for(int d : bloomDay)
        {
            if(d <= day)
            {
                flowers++;

                if(flowers == k)
                {
                    bouquet++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }

        return bouquet >= m;
    }

    int minDays(vector<int>& bloomDay,
                int m,
                int k)
    {
        int n = bloomDay.size();

        if((long long)m * k > n)
        {
            return -1;
        }

        int low =
        *min_element(bloomDay.begin(),
                     bloomDay.end());

        int high =
        *max_element(bloomDay.begin(),
                     bloomDay.end());

        while(low < high)
        {
            int mid =
            low + (high - low) / 2;

            if(canMake(bloomDay, mid, m, k))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return high;
    }
};

/*
Key Learning:
1. Binary Search on Answer pattern.
2. Search over days, not array indices.
3. Use feasibility function to validate answer.
4. Adjacent grouping constraint inside validation.
*/
