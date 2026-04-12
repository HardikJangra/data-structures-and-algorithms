/*
Problem: Fruit Into Baskets
Platform: LeetCode
Pattern: Sliding Window (At Most K Distinct)
Difficulty: Medium

Problem Statement:
You are visiting a farm that has a single row of fruit trees represented by array fruits.
Each tree produces a type of fruit.

You have two baskets, and each basket can hold only one type of fruit.
Return the maximum number of fruits you can pick.

Approach:
This is equivalent to finding the longest subarray containing
at most 2 distinct integers.

1. Use sliding window with hashmap.
2. Expand right pointer.
3. If distinct fruits > 2, shrink from left.
4. Track maximum window size.

Time Complexity: O(n)
Space Complexity: O(1) / O(2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0, high = 0;
        int maxFruit = 0;

        unordered_map<int, int> mp;

        while(high < fruits.size()) {
            mp[fruits[high]]++;

            while(mp.size() > 2) {
                mp[fruits[low]]--;

                if(mp[fruits[low]] == 0) {
                    mp.erase(fruits[low]);
                }

                low++;
            }

            maxFruit = max(maxFruit, high - low + 1);

            high++;
        }

        return maxFruit;
    }
};

/*
Key Learning:
1. At Most K Distinct sliding window template.
2. Same pattern as longest substring with at most K unique chars.
3. Window always valid when distinct count <= 2.
4. Track maximum valid window size.
*/
