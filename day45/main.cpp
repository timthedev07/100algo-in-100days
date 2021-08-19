/**
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 *
 * Fast method:
 * 1. Reverse entire array
 * 2. Reverse first k elements
 * 3. Reverse the rest
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k = k % n;
    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
  }

  void reverse(vector<int> &arr, int start, int end)
  {
    while (start < end)
    {
      int tmp = arr[start];
      arr[start] = arr[end];
      arr[end] = tmp;
      start++, end--;
    }
  }
};
