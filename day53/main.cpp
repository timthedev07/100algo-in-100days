#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

using Coord = pair<int, int>;

class Solution
{
 public:
  int numIslands(vector<vector<char>> &grid)
  {
    int islands = 0;

    // n is the number of rows
    // m is the number of columns
    for (int i = 0, n = grid.size(), m = grid[0].size(); i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (grid[i][j] == '1')
        {
          islands++;
          bfs(grid, i, j, n, m);
        }
      }
    }

    return islands;
  }

 private:
  void bfs(vector<vector<char>> &grid, int row, int col, int n, int m)
  {
    stack<Coord> s;
    // unordered_set<Coord> explored;

    s.push(Coord(row, col));
    // explored.insert(Coord(row, col));

    while (!s.empty())
    {
      Coord last = s.top();
      s.pop();
      // if (explored.count(last)) continue;

      int i = last.first, j = last.second;
      grid[i][j] = '0';
      // explored.insert(last);

      // if you go down a node without overflowing and that node is 1
      if (i + 1 < n && grid[i + 1][j] == '1')
      {
        s.push(Coord(i + 1, j));
      }

      // same thing if you go up one
      if (i - 1 > -1 && grid[i - 1][j] == '1')
      {
        s.push(Coord(i - 1, j));
      }

      // one to the right
      if (j + 1 < m && grid[i][j + 1] == '1')
      {
        s.push(Coord(i, j + 1));
      }

      // one to the left
      if (j - 1 > -1 && grid[i][j - 1] == '1')
      {
        s.push(Coord(i, j - 1));
      }
    }
  }
};
