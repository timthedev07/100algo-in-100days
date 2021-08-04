#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * Day 27 - two sum
 *
 * Time complexity: O(n)
 */
class Solution
{
 public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> hashmap;

    for (int i = 0; i < nums.size(); ++i)
    {
      int complement = target - nums[i];
      if (hashmap.find(complement) != hashmap.end())
      {
        vector<int> res = {i, hashmap[complement]};
        return res;
      }
      hashmap.insert(pair<int, int>(nums[i], i));
    }

    throw "No Solution";
  }
};
