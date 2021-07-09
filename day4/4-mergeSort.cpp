/**
 * Day 4 - Merge Sort
 *
 * Time Complexity: O(n log n)
 *
 *
 * To be honest, I don't know this that well...
 */
#include <iostream>
#include <vector>

#include "../helpers/Helpers.h"

using namespace std;

class Solution
{
 public:
  /**
   * PSEUDO CODE:
   *
   * mergeSort(arr):
   *   If only one item:
   *     return arr
   *   Sort left half of arr
   *   Sort Right half of arr
   *
   *   Return merge two sorted halves;
   *
   *
   */
  template <typename T>
  void solve(vector<T> arr)
  {
    cout << "Original array: " << arrayStringify(arr) << endl;

    arr = mergeSort(arr);

    cout << "Sorted array: " << arrayStringify(arr) << "\n\n";
  }

  template <typename T>
  vector<T> mergeSort(vector<T> arr)
  {
    const size_t size = arr.size();
    if (size == 1)
    {
      return arr;
    }

    // extract the halves/subarrays
    const size_t mid = ceil(size / 2);

    // const vector<T> left = vector<T>(arr.begin(), arr.end() - mid);
    // const vector<T> right = vector<T>(arr.begin() + mid, arr.end());
    const vector<T> left = sliceArray(arr, 0, mid);
    const vector<T> right = sliceArray(arr, mid);
    // cout << "\n=======================\n"
    //<< "Left:\n"
    //<< arrayStringify(left) << endl
    //<< "Right:\n"
    //<< arrayStringify(right) << "\n=======================\n\n";

    return merge(mergeSort(left), mergeSort(right));
  }

  template <typename T>
  vector<T> merge(vector<T> left, vector<T> right)
  {
    vector<T> res;

    size_t leftInd = 0, rightInd = 0;
    size_t leftLen = left.size(), rightLen = right.size();

    while (leftInd < leftLen && rightInd < rightLen)
    {
      if (left.at(leftInd) <= right.at(rightInd))
      {
        res.push_back(left.at(leftInd));
        leftInd++;
        continue;
      }
      if (left.at(leftInd) > right.at(rightInd))
      {
        res.push_back(right.at(rightInd));
        rightInd++;
        continue;
      }
    }

    while (leftInd < leftLen)
    {
      res.push_back(left.at(leftInd));
      leftInd++;
    }

    while (rightInd < rightLen)
    {
      res.push_back(right.at(rightInd));
      rightInd++;
    }

    return res;
  }
};

int main(void)
{
  Solution solution = Solution();
  const vector<string> arr0 = {"apollo", "patreon", "hello", "typescript"};
  const vector<string> arr1 = {
      "somewhere", "influence", "about",       "announced", "fresh",
      "compound",  "cloth",     "tie",         "sucks",     "twice",
      "major",     "phrase",    "cause",       "public",    "lucky",
      "planned",   "essential", "quarter",     "chapter",   "money",
      "animal",    "with",      "equally",     "refer",     "verb",
      "tonight",   "shape",     "cause",       "putting",   "widely",
      "cave",      "gather",    "dry",         "shout",     "wonderful",
      "speed",     "each",      "comfortable", "list",      "opinion",
      "dropped",   "bark"};
  const vector<double> arr2 = {3.4, 1.9, 54.8, 30.6, 77.55};
  solution.solve(arr0);
  solution.solve(arr1);
  solution.solve(arr2);

  return 0;
}
