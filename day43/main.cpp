/**
 * Given a n-ary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root
 * node down to the farthest leaf node.
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
 public:
  int maxDepth(Node *root)
  {
    if (!root) return 0;

    queue<Node *> q;

    q.push(root);

    int res = 0;

    while (!q.empty())
    {
      for (int i = 0, n = q.size(); i < n; ++i)
      {
        Node *curr = q.front();
        q.pop();

        for (Node *child : curr->children)
        {
          q.push(child);
        }
      }

      res++;
    }

    return res;
  }
};
