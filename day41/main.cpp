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
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
 public:
  bool sumOfTwo(vector<int> a, vector<int> b, int target)
  {
    unordered_set<int> setB;

    for (const int &i : b)
    {
      setB.insert(i);
    }

    for (int i = 0, n = a.size(); i < n; ++i)
    {
      int complement = target - a[i];

      if (setB.count(complement) > 0) return true;
    }
    return false;
  }
};

int main(void)
{
  Solution solution = Solution();
  vector<int> a = {1, 2, 3};
  vector<int> b = {10, 20, 30, 40};
  vector<int> a1 = {1, 2, 3};
  vector<int> b1 = {10, 20, 30, 40};

  cout << (solution.sumOfTwo(a, b, 42) ? "true" : "false") << '\n';
  cout << (solution.sumOfTwo(a, b, 50) ? "true" : "false");
}
