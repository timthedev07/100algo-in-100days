/**
 * Day 5 - Binary Search
 *
 * Time Complexity: O(log n) - assuming the input is already sorted
 */
#include <iostream>
#include <vector>

#include "../helpers/Helpers.h"

using namespace std;

class Solution
{
 public:
  template <typename T>
  void solve(vector<T> arr, T target)
  {
    cout << "Target: " << target << " was"
         << (!(binarySearch(arr, target)) ? " not " : " ")
         << "found on array: " << arrayStringify(arr) << endl;
  }

  template <typename T>
  bool binarySearch(vector<T> arr, T target)
  {
    if (arr.empty()) return false;

    size_t size = arr.size();
    size_t mid = floor(size / 2);

    if (arr[mid] == target)
    {
      return true;
    }

    return binarySearch(
        arr[mid] > target ? sliceArray(arr, 0, mid) : sliceArray(arr, mid + 1),
        target);
  }
};

int main(void)
{
  Solution solution = Solution();

  const vector<string> bestTechnologies = {
      "typescript",    "react",  "vue",     "svelte", "express",
      "ruby on rails", "jquery", "asp.net", "django", "flask"};
  const vector<double> arr0 = {4.39, 5.283, 7.5, 9.41};
  const vector<string> faang = {"facebook", "amazon", "apple", "netflix",
                                "google"};

  solution.solve<string>(bestTechnologies, "angular");
  solution.solve<double>(arr0, 4.39);
  solution.solve<string>(faang, "google");
}
