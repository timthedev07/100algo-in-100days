/**
 * Day 1: Linear Search
 */

#include <iostream>
#include <vector>

using namespace std;

string arrayStringify(vector<int> arr)
{
  if (arr.empty())
  {
    return "[  ]";
  }
  string res = "[ ";

  for (size_t i = 0, n = arr.size(); i < n; ++i)
  {
    res.append(to_string(arr.at(i)));
    if (i != n - 1)
    {
      res.append(", ");
    }
  }
  res.append(" ]");

  return res;
}

class Solution
{
 public:
  void solve(vector<int> arr, int target)
  {
    for (size_t i = 0, n = arr.size(); i < n; ++i)
    {
      if (arr.at(i) == target)
      {
        cout << "Target found at index " << i
             << " on array: " << arrayStringify(arr) << endl;
        return;
      }
    }
    cout << "Target not found" << endl;
  }
};

int main(void)
{
  Solution solution = Solution();

  const vector<int> arr1 = {1, 3, 5, 7, 9};
  const vector<int> arr2 = {29, 84, 49, 61, 33};
  solution.solve(arr1, 4);
  solution.solve(arr2, 61);
  return 0;
}
