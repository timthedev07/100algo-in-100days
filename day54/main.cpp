/**
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 *
 * The area of an island is the number of cells with a value 1 in the island.
 *
 * Return the maximum area of an island in grid. If there is no island, return
 * 0.
 *
 */
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

using Coord = pair<int, int>;

class Solution
{
 public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    for (int i = 0, n = grid.size(), m = grid[0].size(); i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (grid[i][j] == 1)
        {
          bfs(grid, i, j, n, m);
        }
      }
    }

    return maxCount;
  }

 private:
  int maxCount = 0;
  void bfs(vector<vector<int>> &grid, int row, int col, int n, int m)
  {
    stack<Coord> s;
    int count = 0;
    unordered_set<string> explored;

    s.push(Coord(row, col));

    while (!s.empty())
    {
      Coord last = s.top();
      s.pop();

      int i = last.first, j = last.second;
      grid[i][j] = 0;
      string str = "r" + to_string(i) + "c" + to_string(j);

      if (explored.count(str)) continue;
      explored.insert(str);
      count++;
      if (i + 1 < n && grid[i + 1][j] == 1)
      {
        s.push(Coord(i + 1, j));
      }
      if (i - 1 > -1 && grid[i - 1][j] == 1)
      {
        s.push(Coord(i - 1, j));
      }

      // one to the right
      if (j + 1 < m && grid[i][j + 1] == 1)
      {
        s.push(Coord(i, j + 1));
      }

      // one to the left
      if (j - 1 > -1 && grid[i][j - 1] == 1)
      {
        s.push(Coord(i, j - 1));
      }
    }

    maxCount = max(maxCount, count);
  }
};
