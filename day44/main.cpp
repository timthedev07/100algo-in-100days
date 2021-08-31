/**
 * Given the root of a binary tree, return the maximum width of the given tree.
 * The maximum width of a tree is the maximum width among all levels.
 */
#include <deque>
#include <iostream>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right)
  {
  }
};

using MapPair = pair<unsigned long long, TreeNode *>;

class Solution
{
 public:
  int widthOfBinaryTree(TreeNode *root)
  {
    deque<MapPair> q;
    q.push_back(MapPair(1, root));

    unsigned long long res = 0;

    while (!q.empty())
    {
      int n = q.size();

      res = max((q[n - 1].first - q[0].first) + 1, res);

      for (int i = 0; i < n; ++i)
      {
        MapPair popped = q.front();
        q.pop_front();

        if (!popped.second) continue;

        if (popped.second->left)
        {
          q.push_back(MapPair(popped.first * 2, popped.second->left));
        }
        if (popped.second->right)
        {
          q.push_back(MapPair(popped.first * 2 + 1, popped.second->right));
        }
      }
    }

    return res;
  }
};

int main(void) {}
