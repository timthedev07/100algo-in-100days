/**
 * day 15 - Define minimum and maximum element of array
 *
 * Time complexity: O(n)
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  template <typename T>
  void solve(vector<T> arr)
  {
    T min;
    T max;

    for (int i = 0, n = arr.size(); i < n; i++)
    {
      if (i == 0)
      {
        min = max = arr.at(i);
        continue;
      }

      T curr = arr.at(i);
      if (curr < min)
      {
        min = curr;
      }
      if (curr > max)
      {
        max = curr;
      }
    }

    cout << "Min: " << min << " Max: " << max << "\n";
  }
};

int main(void)
{
  Solution solution = Solution();

  const vector<int> arr0 = {1, 2, 3, 4, 5};
  const vector<string> arr1 = {"i am the largest", "i am t- ok fine",
                               "i am actually the smallest"};

  solution.solve(arr0);
  solution.solve(arr1);
}
