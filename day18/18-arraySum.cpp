/**
 * Day 18 - arraySum
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
  void solve(vector<int> arr)
  {
    cout << "Input: " << arrayStringify(arr) << '\n';

    int res = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      res += arr.at(i);
    }
    cout << "Output: " << res << '\n';
  };
};

int main(void)
{
  Solution solution = Solution();

  const vector<vector<int>> arr0 = {
      {34, 52, 17, 65}, {74, 48, 13, 85}, {27, 84, 86, 62}, {10, 94, 43, 28}};

  solution.solve(arr0);
}
