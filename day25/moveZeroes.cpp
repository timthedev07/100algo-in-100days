/*
 * Day 25 - Move zeroes to the end of the array without altering the relative
 * order of the non-zero elements
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  void moveZeroes(vector<int> &nums)
  {
    int m = 0;
    vector<int>::iterator it = nums.begin();

    while (it != nums.end())
    {
      if (*it == 0)
      {
        m++;
        nums.erase(it);
      }
      else
      {
        ++it;
      }
    }
    for (int i = 0; i < m; i++)
    {
      nums.push_back(0);
    }
  }
};
