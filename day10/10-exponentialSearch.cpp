/**
 * Day 10 - Exponential Search
 *
 * Time complexity: O(log n);
 *
 * In the implementation of this algorithms, I also did iterative binary search,
 * which I wanted to leave another day...
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
    int res = expoSearch(arr, target);
    cout << "Target: " << target << " was "
         << (res > -1 ? "found on index of " + to_string(res) : "not found on ")
         << "array: " << arrayStringify(arr) << endl;
  }

  template <typename T>
  int expoSearch(vector<T> arr, T target)
  {
    int i = 1;
    int n = arr.size();

    while (i < n && arr[i] < target)
    {
      i *= 2;
    }

    return binSearch(arr, target, i / 2, min(i, n - 1));
  }

 private:
  template <typename T>
  int binSearch(vector<T> arr, T target)
  {
    return binSearch(arr, target, 0, arr.size() - 1);
  }

  template <typename T>
  int binSearch(vector<T> arr, T target, int low, int high)
  {
    int mid = 0;
    while (high > low)
    {
      mid = ceil((high + low) / 2);

      if (arr[mid] == target)
      {
        return mid;
      }

      if (target <= arr[mid])
      {
        high = mid;
      }
      else if (target > arr[mid])
      {
        low = mid + 1;
      }
    }

    if (arr[low] == target)
    {
      return low;
    }

    return -1;
  }
};

int main(void)
{
  Solution solution = Solution();

  const vector<int> arr0 = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
  const vector<string> bestTechnologies = {
      "typescript",    "react",  "vue",     "svelte", "express",
      "ruby on rails", "jquery", "asp.net", "django", "flask"};
  const vector<double> arr1 = {4.39, 5.283, 7.5, 9.41};
  const vector<string> faang = {"facebook", "amazon", "apple", "netflix",
                                "google"};

  solution.solve<string>(bestTechnologies, "angular");
  solution.solve<double>(arr1, 4.39);
  solution.solve<string>(faang, "apple");
}
