#include <vector>

using namespace std;

class Solution
{
  int maxSubArray(vector<int> &arr)
  {
    int best = arr[0];

    int curr = arr[0];

    for (int i = 1, n = arr.size(); i < n; ++i)
    {
      // if adding the current item to the existing sub array
      // would resulter in a greater sum than starting a new sub array from the
      // current item set best to be curr + arr[i]
      curr = max(curr + arr[i], arr[i]);
      best = max(curr, best);
    }
    return best;
  }
  int bruteForce(vector<int> arr)
  {
    int best = numeric_limits<int>::min();
    for (int i = 0, n = arr.size(); i < n; ++i)
    {
      int currSum = 0;
      for (int j = i; j < n; ++j)
      {
        currSum += arr[j];
        if (currSum > best) best = currSum;
      }
    }
    return best;
  }
}
