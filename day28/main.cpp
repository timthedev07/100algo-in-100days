/**
 * Day 28 - Two sum but the input sequence is sorted
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int ptr0 = 0;
    int ptr1 = nums.size() - 1;

    while (ptr0 < ptr1)
    {
      int sum = nums[ptr0] + nums[ptr1];

      if (sum < target)
      {
        ptr0++;
      }
      else if (sum > target)
      {
        ptr1--;
      }
      else
      {
        vector<int> res = {++ptr0, ++ptr1};
        return res;
      }
    }

    vector<int> res = {++ptr0, ++ptr1};
    return res;
  }
};

int main(void) {}
