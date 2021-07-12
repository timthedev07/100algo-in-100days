/**
 * Day 6 - Invert a binary tree
 *
 */
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Node
{
 public:
  T val;
  Node<T> *left;
  Node<T> *right;

  Node<T>(T value, Node<T> *leftPtr = nullptr, Node<T> *rightPtr = nullptr)
  {
    val = value;
    left = leftPtr;
    right = rightPtr;
  }

  void printBT(const std::string &prefix, const Node<T> *node, bool isLeft)
  {
    if (node != nullptr)
    {
      std::cout << prefix;

      std::cout << (isLeft ? "├──" : "└──");

      // print the value of the node
      std::cout << node->val << std::endl;

      // enter the next tree level - left and right branch
      printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
      printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
  }

  void print() { printBT("", this, false); }
};

class Solution
{
 public:
  template <typename T>
  void solve(Node<T> *root)
  {
    cout << "Original tree: \n";
    root->print();
    root = revertBinaryTree(root);
    cout << "Reverted tree: \n";
    root->print();
    cout << endl << endl;
  }

  template <typename T>
  Node<T> *revertBinaryTree(Node<T> *node)
  {
    if (!node)
    {
      return nullptr;
    }

    if (node->left)
    {
      node->left = revertBinaryTree(node->left);
    }
    if (node->right)
    {
      node->right = revertBinaryTree(node->right);
    }
    Node<T> *tmp = new Node<T>(node->val);
    tmp->left = node->right;
    tmp->right = node->left;

    return tmp;
  }
};

int main(void)
{
  Solution solution = Solution();

  Node<int> l01 = Node<int>(0);
  Node<int> l02 = Node<int>(7);
  Node<int> l0 = Node<int>(2, &l01, &l02);
  Node<int> l11 = Node<int>(4);
  Node<int> l12 = Node<int>(13);
  Node<int> l1 = Node<int>(9, &l11, &l12);
  Node<int> root0 = Node<int>(5, &l0, &l1);

  solution.solve(&root0);
}
