/**
 *
 * Day 34
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order. You must write an algorithm with O(log n) runtime
 * complexity.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int searchInsert(vector<int> &nums, int target)
  {
    return bigassSearch(nums, target, 0, nums.size() - 1);
  }

  int bigassSearch(vector<int> &arr, int target, int l, int h)
  {
    while (h > l)
    {
      int mid = ceil((l + h) / 2);

      if (arr[mid] == target)
      {
        return mid;
      }
      else if (arr[mid] < target)
      {
        l = mid + 1;
      }
      else
      {
        h = mid;
      }
    }

    return target > arr[l] ? l + 1 : l;
  }
};
