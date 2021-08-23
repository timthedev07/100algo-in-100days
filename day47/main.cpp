#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  int singleNumber(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, int> hashmap;
    for (int i = 0; i < n; ++i)
    {
      if (hashmap.find(nums[i]) == hashmap.end())
        hashmap.insert(pair<int, int>(nums[i], 1));
      else
        hashmap[nums[i]]++;
    }

    for (auto pair : hashmap)
    {
      if (pair.second < 2) return pair.first;
    }
    return -1;
  }
};
