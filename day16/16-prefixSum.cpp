/**
 * Day 16 - Prefix sum of array
 *
 * Time complexity: O(n)
 *
 */
#include <iostream>
#include <vector>

#include "../helpers/Helpers.h"

using namespace std;

class Solution
{
 public:
  template <typename T>
  void solve(vector<T> arr)
  {
    cout << "Input: " << arrayStringify(arr) << '\n';
    cout << "Output: " << arrayStringify(prefixSum(arr)) << '\n';
  };

 private:
  template <typename T>
  vector<T> prefixSum(vector<T> arr)
  {
    const size_t n = arr.size();
    vector<T> res = {};

    for (int i = 0; i < n; ++i)
    {
      res.push_back(i == 0 ? arr.at(0) : res.at(i - 1) + arr.at(i));
    }

    return res;
  }
};

int main(void)
{
  Solution solution = Solution();

  const vector<int> arr0 = {10, 20, 10, 5, 15};
  const vector<string> arr1 = {"Join ", "us ", "together ", "please ",
                               "hooman!"};

  solution.solve(arr0);
  solution.solve(arr1);
}
