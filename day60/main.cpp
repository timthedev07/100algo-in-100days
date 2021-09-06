/**
 * Level order traversal of binary tree
 */
#include <queue>
#include <vector>

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
class Solution
{
 public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
      int n = q.size();

      vector<int> level;

      for (int i = 0; i < n; ++i)
      {
        TreeNode *popped = q.front();
        q.pop();

        if (popped->left) q.push(popped->left);
        if (popped->right) q.push(popped->right);

        level.push_back(popped->val);
      }

      res.push_back(level);
    }

    return res;
  }
};
