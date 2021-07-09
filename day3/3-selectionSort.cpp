/**
 * Day 3 - Selection sort
 *
 * Time complexity O(n^2)
 */

#include <iostream>
#include <string>
#include <vector>

#include "../helpers/Helpers.h"

using namespace std;

class Solution
{
 public:
  template <typename T>
  void solve(vector<T> arr)
  {
    cout << endl << "Original: " << arrayStringify(arr) << endl;

    int n = arr.size();
    for (size_t i = 0; i < n; ++i)
    {
      // remember the smallest item
      size_t smallestInd;
      T smallest;
      for (size_t j = i; j < n; j++)
      {
        if (j == i || smallest > arr.at(j))
        {
          smallest = arr.at(j);
          smallestInd = j;
        }
      }
      T temp = arr[i];
      arr[i] = smallest;
      arr[smallestInd] = temp;
    }

    cout << "Sorted: " << arrayStringify(arr) << endl << endl;
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
