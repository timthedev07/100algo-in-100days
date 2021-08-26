/**
 * Given an array of integers nums and an integer k, determine whether there are
 * two distinct indices i and j in the array where nums[i] = nums[j] and the
 * absolute difference between i and j is less than or equal to k.
 *
 */
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool containsCloseNums(vector<int> nums, int k)
  {
    // map values in the array to their indices
    unordered_map<int, int> map;

    for (int i = 0, n = nums.size(); i < n; ++i)
    {
      if (map.count(nums[i]))
      {
        if (abs(map[nums[i]] - i) <= k) return true;
        map[nums[i]] = i;
      }
      else
        map.insert(pair<int, int>(nums[i], i));
    }

    return false;
  }
};
