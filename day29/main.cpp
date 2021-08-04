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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<vector<int>> paths = {};
    vector<int> curr = {};

    if (root != nullptr) recurse(root, targetSum, curr, &paths);

    return paths;
  }

  void recurse(TreeNode *node, int target, vector<int> curr,
               vector<vector<int>> *paths)
  {
    target -= node->val;

    curr.push_back(node->val);

    // got a right path
    if (target == 0 && node->left == nullptr && node->right == nullptr)
    {
      paths->push_back(curr);
      return;
    }

    if (node->left != nullptr)
    {
      recurse(node->left, target, curr, paths);
    }

    if (node->right != nullptr)
    {
      recurse(node->right, target, curr, paths);
    }
  }
};

int main(void) {}
