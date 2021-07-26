/**
 * Day 21 - Sort colors(leet code)
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 in-place so that objects of the same color are adjacent, with the colors in the
 order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 blue, respectively.

 * You must solve this problem without using the library's sort function.
 *
 * Example:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 * Complexity: O(n)
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  void sortColors(vector<int> &nums)
  {
    // since we know that there is only going to be three different
    // values [0, 1, 2], we can perform couting sort on the array.

    const int k = 3;
    unordered_map<int, int> record = {};

    // fill the record with zeros
    // O(k)
    for (int i = 0; i < k; ++i)
    {
      record.insert(pair<int, int>(i, 0));
    }

    // iterate over the nums array and update the record
    // O(n)
    for (int i = 0, n = nums.size(); i < n; ++i)
    {
      record[nums.at(i)]++;
    }

    // put all the items in order
    // O(n)
    nums.clear();
    for (int i = 0; i < k; ++i)
    {
      for (int j = 0, m = record[i]; j < m; ++j)
      {
        nums.push_back(i);
      }
    }
  }
};
