/*
Problem: Minimum Meeting Rooms
Platform: LeetCode / GFG (Minimum Platforms equivalent)
Pattern: Greedy + Two Pointers (Timeline)
Folder: 10_Greedy_Intervals
Difficulty: Medium

Problem Statement:
Given two arrays start[] and end[] representing start and end times of meetings,
find the minimum number of meeting rooms required so that all meetings can be held.

Approach:
1. Sort start times and end times separately.
2. Use two pointers:
   - If next meeting starts before current one ends → need new room.
   - Else → free a room.
3. Track maximum rooms needed at any time.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0;
        int rooms = 0, maxRooms = 0;

        while(i < n) {
            if(start[i] < end[j]) {
                rooms++;
                i++;
            } else {
                rooms--;
                j++;
            }

            maxRooms = max(maxRooms, rooms);
        }

        return maxRooms;
    }
};

/*
Key Learning:
1. Treat start/end times as timeline events.
2. If meeting starts before another ends → extra room needed.
3. Track peak overlap.
4. Same logic as Minimum Platforms problem.
*/
