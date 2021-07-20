/**
 * Day 14 - sum digits
 */
#include <iostream>

using namespace std;

class Solution
{
public:
  void solve(int num)
  {
    int res = 0;
    while (num != 0)
    {
      res = res + num % 10;
      num = num / 10;
    }
    cout << res << "\n";
  }

private:
  /* data */
};

int main(void)
{
  Solution solution = Solution();
  solution.solve(100);
  solution.solve(543);
  solution.solve(85841233);
}