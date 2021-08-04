/**
 * Day 29 - Path sum II (LeetCode)
 *
 * Given the root of a binary tree and an integer targetSum.
 * Return all root-to-leaf paths where each path's sum equals targetSum.
 * A leaf is a node with no children.
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
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
  bool hasPathSum(TreeNode *root, int target)
  {
    if (root != nullptr)
    {
      target -= root->val;
      if (target == 0 && root->left == nullptr && root->right == nullptr)
      {
        return true;
      }
      else
      {
        bool res = false;
        if (root->right != nullptr)
        {
          res = hasPathSum(root->right, target);
        }
        if (res)
        {
          return true;
        }
        if (root->left != nullptr)
        {
          res = hasPathSum(root->left, target);
        }
        if (res)
        {
          return true;
        }
      }
    }
    return false;
  }
};
int main(void) {}
