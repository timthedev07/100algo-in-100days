/**
 *
 *
In a town, there are n people labeled from 1 to n. There is a rumor that one
of these people is secretly the town judge.

If the town judge exists, then:

  - The town judge trusts nobody.
  - Everybody (except for the town judge) trusts the town judge.
  - There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where trust[i] = [ai, bi] representing that the
person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be
identified, or return -1 otherwise.
 *
 */
#include <vector>

using namespace std;

class Solution
{
 public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    n += 1;
    vector<int> trustCount(n, 0);

    for (const vector<int> &trustValue : trust)
    {
      trustCount[trustValue[0]]--;
      trustCount[trustValue[1]]++;
    }

    for (int i = 1; i < n; i++)
    {
      if (trustCount[i] == n - 2) return i;
    }

    return -1;
  }
};
