/**
 *
 *
 * You have an unsorted array arr of non-negative integers and a number s. Find
 * a longest contiguous subarray in arr that has a sum equal to s. Return two
 * integers that represent its inclusive bounds. If there are several possible
 * answers, return the one with the smallest left bound. If there are no
 answers,
 * return [-1].
 * Your answer should be 1-based, meaning that the first position of the array
 is 1 instead of 0.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<int> findLongestSubarrayBySum(int target, vector<int> arr)
  {
    if (arr.empty()) return {-1};

    int a = 0, b = 0;
    int n = arr.size();
    int sum = 0;
    vector<int> res = {-1};

    while (b < n)
    {
      sum += arr[b];

      // while the sum is greater than the target sum and the two pointers have
      // not yet met
      while (a < b && sum > target)
      {
        // pop items off on the left side
        sum -= arr[a++];
      }

      // if the current contiguous subarray's elements sum to target,
      // and it's better than the previous subarray
      if (sum == target && (res.size() == 1 || res[1] - res[0] < b - a))
      {
        // update result
        res = {a + 1, b + 1};
      }

      b++;
    }

    return res;
  }
};

int main(void)
{
  Solution solution = Solution();
  vector<int> a = {1, 2, 3, 4};
}
