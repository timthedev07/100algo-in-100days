/**
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 * Screw it i'm mentally exhausted after school.
 *
[
        [1],
       [1,1],
      [1,2,1],
     [1,3,3,1],
    [1,4,6,4,1]
]
 *
 */
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> res;
    vector<int> row0 = {1};
    res.push_back(row0);

    for (int i = 1; i < numRows; ++i)
    {
      vector<int> prevRow = res[i - 1];
      vector<int> currRow;

      currRow.push_back(1);

      for (int j = 1; j < i; ++j)
      {
        currRow.push_back(prevRow[j] + prevRow[j - 1]);
      }

      currRow.push_back(1);

      res.push_back(currRow);
    }

    return res;
  }
};
