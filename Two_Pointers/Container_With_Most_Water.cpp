/*
Problem: Container With Most Water
Platform: LeetCode
Pattern: Two Pointers
Folder: 01_Two_Pointers
Difficulty: Medium

Problem Statement:
Given an array height where each element represents
the height of a vertical line, find two lines that,
together with the x-axis, form a container that
holds the maximum amount of water.

Return the maximum area of water the container can store.

Approach:
1. Place one pointer at the beginning and one at the end.
2. Calculate current area:
   Area = min(height[left], height[right]) * (right - left)
3. Update maximum area.
4. Move the pointer with smaller height:
   - Because the smaller height limits the container.
5. Continue until pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();

        int i = 0;
        int j = n - 1;

        int maxWater = 0;

        while(i < j) {

            int h = min(height[i], height[j]);
            int w = j - i;

            int area = h * w;

            maxWater = max(maxWater, area);

            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return maxWater;
    }
};

/*
Key Learning:
1. Area depends on:
   - Minimum height
   - Distance between pointers
2. Smaller height is the bottleneck.
3. Moving the taller pointer can never increase area.
4. Classic Two Pointer optimization problem.
*/
