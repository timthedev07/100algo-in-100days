/**
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res = {intervals[0]};
    for (int i = 1; i < n; ++i)
    {
      if (res.back()[1] < intervals[i][0])
        res.push_back(intervals[i]);
      else
      {
        res.back()[1] = max(intervals[i][1], res.back()[1]);
      }
    }
    return res;
  }
};
