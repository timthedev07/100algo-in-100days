/**
 * Day 8 - Insertion sort
 *
 * Time complexity: O(n^2)
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
    cout << "Original array: " << arrayStringify(arr) << endl;
    cout << "Sorted array: " << arrayStringify(insertionSort(arr)) << endl;
  }

 private:
  template <typename T>
  vector<T> insertionSort(vector<T> arr)
  {
    int j = 0;
    for (int i = 1, n = arr.size(); i < n; i++)
    {
      T curr = arr[i];
      j = i - 1;

      while (j >= 0 && arr[j] > curr)
      {
        arr[j + 1] = arr[j];
        j--;
      }

      arr[j + 1] = curr;
    }
    return arr;
  }
};

int main(void)
{
  Solution solution = Solution();

  const vector<string> arr0 = {"d", "a", "e", "c", "f", "b"};
  const vector<double> arr1 = {3.1, 75.3, 58.2, 60.5, 35.535};

  solution.solve(arr0);
  solution.solve(arr1);
}
