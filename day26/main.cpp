/**
 * Day 26 - Container With Most Water(LeetCode)
 * https://leetcode.com/problems/container-with-most-water/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int maxArea(vector<int> &height)
  {
    int best = 0;
    int ptr0 = 0;
    int ptr1 = height.size() - 1;

    while (ptr0 < ptr1)
    {
      int m = min(height[ptr0], height[ptr1]);
      best = max(best, m * (ptr1 - ptr0));

      if (height[ptr0] == m)
        ptr0++;
      else
        ptr1--;
    }
    return best;
  }
};

int main(void) {}
