#include <vector>

using namespace std;

class Solution
{
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
