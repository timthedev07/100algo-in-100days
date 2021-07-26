/**
 * Day 22 - Convert a sorted array to a binary search tree (leet code)
 *
 * Given an integer array nums where the elements are sorted in ascending order,
 * convert it to a height-balanced binary search tree.
 * A height-balanced binary tree is a binary tree in which the depth of
 * the two subtrees of every node never differs by more than one.
 *
 * Time complexity: O(???)
 *
 *
 * YOU KNOW WHAT!!!! MY ANSWER GOT ACCEPTED ON THE FIRST SUBMIT!!!!!!
 *
 * DUDE!!!!
 *
 * LIKE, I WAS LITERALLY CODING THIS ALGORITHM FOR LIKE 30 MINUTES,
 * AND IT LITERALLY RUNS LIKE BUTTER ALTHOUGH IT IS NOT THE FASTEST
 *
 */
#include <iostream>
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
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    int size = nums.size();
    int mid = ceil(size / 2);

    TreeNode *root = new TreeNode(nums[mid]);

    vector<int> left = vector<int>(nums.begin(), nums.begin() + mid);
    vector<int> right = vector<int>(nums.begin() + mid + 1, nums.end());

    pickAndInsert(right, root, true);
    pickAndInsert(left, root, false);

    return root;
  }

  void pickAndInsert(vector<int> &nums, TreeNode *tree,
                     bool side)  // true == right
  {
    // so the idea here is that,
    // if the array is sorted, we know that
    // if we pick the middle element of the array
    // the and divide it into halves,
    // all the items in the left half are going to be
    // smaller than it, and all the items in the right
    // half are going to be larger than it.
    // Now, the important part of this that we
    // apply that logic recursively to the divided halves.

    if (nums.empty())
    {
      return;
    }

    int mid = ceil(nums.size() / 2);

    TreeNode *child = new TreeNode(nums[mid]);

    if (side)
    {
      tree->right = child;
    }
    else
    {
      tree->left = child;
    }

    vector<int> left = vector<int>(nums.begin(), nums.begin() + mid);
    vector<int> right = vector<int>(nums.begin() + mid + 1, nums.end());

    pickAndInsert(right, child, true);
    pickAndInsert(left, child, false);
  }
};

int main(void) {}
