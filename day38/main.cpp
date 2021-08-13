/**
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times. You
 * may assume that the majority element always exists in the array.
 *
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  int majorityElement(vector<int> &nums)
  {
    unordered_map<int, int> hashmap = {};
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
      if (hashmap.find(nums[i]) == hashmap.end())
        hashmap.insert(pair<int, int>(nums[i], 1));
      else
        hashmap[nums[i]]++;
    }

    for (int i = 0; i < n; ++i)
    {
      int times = hashmap[nums[i]];
      if (times > n / 2) return nums[i];
    }
    return -1;
  }
};
