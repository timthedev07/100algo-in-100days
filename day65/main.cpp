/**
You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed, the only constraint stopping you from
robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into
on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the
police.
 */
#include <vector>

using namespace std;

class Solution
{
 public:
  int rob(vector<int> &houses)
  {
    int n = houses.size();
    if (n == 1) return houses[0];
    int a = max(houses[0], houses[1]);
    if (n == 2) return a;

    vector<int> dp(n, 0);
    // what is the maximum amout of money we can rob at the ith house?
    // well, in this case it's simply the first house.
    dp[0] = houses[0];
    // then here it's either the first house or the second house,
    // we can't rob them at the same time or we'll have to go to the jail.
    // so we pick the richer one
    dp[1] = a;

    for (int i = 2; i < n; ++i)
    {
      // we want to decide if we get more money by
      // robbing the previous house, or by
      // robbing the house before the last with the current one
      dp[i] = max(dp[i - 1], dp[i - 2] + houses[i]);
    }

    // return the maximum money we can get, which is the last element of dp
    return dp[n - 1];
  }
};
