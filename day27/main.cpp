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
      int compliment = target - nums[i];
      if (hashmap.find(compliment) != hashmap.end())
      {
        vector<int> res = {i, hashmap[compliment]};
        return res;
      }
      hashmap.insert(pair<int, int>(nums[i], i));
    }

    throw "No Solution";
  }
};
