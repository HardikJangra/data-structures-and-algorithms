/*
Problem: Top K Frequent Elements
Platform: LeetCode
Pattern: Heap + HashMap
Folder: 18_Heap
Difficulty: Medium

Problem Statement:
Given an integer array nums and an integer k,
return the k most frequent elements.

You may return the answer in any order.

Approach:
1. Count the frequency of every element using a HashMap.
2. Maintain a Min Heap of size k storing:
   {frequency, element}
3. If heap size exceeds k:
   - Remove the least frequent element.
4. The heap finally contains the k most frequent elements.
5. Extract elements from the heap.

Time Complexity: O(n log k)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Count frequencies
        for(int x : nums) {
            mp[x]++;
        }

        // Min Heap: {frequency, element}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for(auto &it : mp) {

            pq.push({it.second, it.first});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

/*
Key Learning:
1. Combine HashMap and Heap.
2. HashMap stores frequencies.
3. Min Heap maintains the top k frequent elements.
4. Classic Top-K interview problem.
*/
