#include <iostream>
#include <vector>

#include "../helpers/Helpers.h"

using namespace std;

class Solution
{
 public:
  vector<int> productExceptSelf(vector<int> &arr)
  {
    int n = arr.size();

    vector<int> a = {};
    vector<int> b(n, 0);
    vector<int> res = {};

    a.push_back(1);
    b[n - 1] = 1;

    for (int i = 1; i < n; ++i)
    {
      a.push_back(arr[i - 1] * a[i - 1]);
    }

    for (int i = n - 2; i >= 0; --i)
    {
      b[i] = arr[i + 1] * b[i + 1];
    }

    cout << arrayStringify(a) << endl;
    cout << arrayStringify(b) << endl;

    for (int i = 0; i < n; ++i)
    {
      res.push_back(a[i] * b[i]);
    }

    return res;
  }
};

int main(void)
{
  Solution solution = Solution();
  vector<int> a = {1, 2, 3, 4};
  solution.productExceptSelf(a);
}
