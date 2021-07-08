/**
 * Day 1: Linear Search
 * 
 * Time complexity: O(n)
 */

#include <iostream>
#include <vector>
#include "../helpers/Helpers.h"

using namespace std;

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

  vector<int> arr1 = {1, 3, 5, 7, 9};
  vector<int> arr2 = {29, 84, 49, 61, 33};
  solution.solve(arr1, 4);
  solution.solve(arr2, 61);
  return 0;
}
