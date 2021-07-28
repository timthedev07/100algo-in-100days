/**
 * Day 24 - Squares of a Sorted Array
 *
 */

#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    vector<int> res = {};

    int ptr0 = 0;
    int size = nums.size();

    if (nums.back() <= 0)
    {
      ptr0 = size - 1;
    }
    else
    {
      int best = std::numeric_limits<int>::max();

      vector<int>::iterator it = nums.begin();

      while (it != nums.end())
      {
        if (abs(*it) < best)
        {
          best = abs(*it);
          ptr0 = it - nums.begin();
        }
        ++it;
      }
    }

    int ptr1 = ptr0;

    while (ptr0 >= 0 && ptr1 < size)
    {
      if (ptr0 != ptr1)
      {
        int x = pow(nums[ptr0], 2);
        int y = pow(nums[ptr1], 2);

        if (x < y)
        {
          res.push_back(x);

          ptr0--;
        }
        else
        {
          res.push_back(y);

          ptr1++;
        }
      }
      else
      {
        res.push_back(pow(nums[ptr0], 2));
        ptr0--;
        ptr1++;
      }
    }

    while (ptr0 >= 0)
    {
      res.push_back(pow(nums[ptr0], 2));
      ptr0--;
    }
    while (ptr1 < size)
    {
      res.push_back(pow(nums[ptr1], 2));
      ptr1++;
    }

    return res;
  }
};
