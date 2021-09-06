/**
 * Given the root of a binary tree, return the average value of the nodes on
 * each level in the form of an array. Answers within 10-5 of the actual answer
 * will be accepted.
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
  vector<double> averageOfLevels(TreeNode *root)
  {
    vector<double> res;
    if (!root) return res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int n = q.size();
      double levelSum = 0;

      for (int i = 0; i < n; ++i)
      {
        TreeNode *popped = q.front();
        q.pop();

        if (popped->left) q.push(popped->left);
        if (popped->right) q.push(popped->right);

        levelSum += popped->val;
      }
      double avg = levelSum / n;
      res.push_back(avg);
    }

    return res;
  }
};
