#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> res = {};

    recurse(root, &res);

    return res;
  }
  void recurse(TreeNode *node, vector<int> *res)
  {
    if (!node)
    {
      return;
    }
    res->push_back(node->val);
    recurse(node->left, res);
    recurse(node->right, res);
  };
