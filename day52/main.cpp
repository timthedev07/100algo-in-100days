/**
 * Day 52:
 *
 * You are climbing a staircase that has n steps. You can take the steps either
 * 1 or 2 at a time. Calculate how many distinct ways you can climb to the top
 * of the staircase.
 */
#include <unordered_map>

using namespace std;

class Solution
{
 public:
  int recurse(int n, unordered_map<int, int> &memo)
  {
    if (n <= 1) return 1;
    if (memo.count(n)) return memo[n];
    int res = recurse(n - 2, memo) + recurse(n - 1, memo);
    memo.insert(pair<int, int>(n, res));
    return res;
  }

  int climbingStairs(int n)
  {
    unordered_map<int, int> memo;
    return recurse(n, memo);
  }
}
