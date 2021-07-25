/**
 * Day 19 - Convert an array to reduced form
 *
 * Time complexity: O(n log n)
 *
 */
#include <stdlib.h>

#include <iostream>
#include <unordered_map>
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
    cout << "Output: " << arrayStringify(coordCompression(arr)) << '\n';
  };

private:
  template <typename T>
  vector<int> coordCompression(vector<T> arr)
  {
    vector<int> res = {};
    vector<T> sorted(arr);

    // sort array
    sort(sorted.begin(), sorted.end());

    unordered_map<T, int> hashmap;

    size_t n = arr.size();
    for (int i = 0; i < n; i++)
    {
      hashmap.insert(pair<T, int>(sorted.at(i), i));
    }

    for (int i = 0; i < n; i++)
    {
      int element = hashmap.at(arr.at(i));
      res.push_back(element);
    }

    return res;
  }
};

int main(void)
{
  Solution solution = Solution();

  const vector<int> arr0 = {5, 10, 40, 30, 20};
  const vector<string> arr1 = {"a", "z", "h", "c", "y", "p"};

  solution.solve(arr0);
  solution.solve(arr1);
}
