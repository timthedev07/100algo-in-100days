/**
 * Day 2 - Bubble sort
 */

#include <iostream>
#include <string>
#include <vector>

#include "../helpers/helpersModule.h"

using namespace std;

template <typename T>
string arrayStringify(vector<T> arr)
{
  if (arr.empty())
  {
    return "[  ]";
  }
  string res = "[ ";

  for (size_t i = 0, n = arr.size(); i < n; ++i)
  {
    res.append("" + (arr.at(i)));
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
  template <typename T>
  void solve(vector<T> arr)
  {
    cout << "Original: " << arrayStringify(arr) << endl;
    int n = arr.size();
    for (size_t i = 1; i < n; ++i)
    {
      if (arr.at(i) < arr.at(i - 1))
      {
        T temp = arr.at(i);
        arr[i] = arr.at(i - 1);
        arr[i - 1] = temp;
      }
    }
    cout << "Sorted: " << arrayStringify(arr) << endl;
  }
};

int main(void)
{
  Solution solution = Solution();
  const vector<string> arr0 = {"apollo", "patreon", "hello", "typescript"};
  solution.solve(arr0);
  return 0;
}
