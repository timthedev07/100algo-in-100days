#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int findMin(vector<int> &arr)
  {
    int l = 0;
    int h = arr.size() - 1;

    if (arr.size() == 1)
    {
      return arr[0];
    }

    while (l < h)
    {
      int mid = l + (h - l) / 2;

      if (mid > 0 && arr[mid] < arr[mid - 1])
      {
        return arr[mid];
      }
      if (arr[mid] > arr[h] && arr[mid] >= arr[l])
      {
        l = mid + 1;
      }
      else
      {
        h = mid - 1;
      }
    }
    return arr[l];
  }
};

int main(void)
{
  Solution solution = Solution();
  vector<int> arr0 = {2, 3, 4, 5, 1};

  cout << solution.findMin(arr0) << endl;
}
