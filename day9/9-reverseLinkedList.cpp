/**
 * Day 9 - Reverse a Singly Linked List
 *
 * Time complexity:  O(n)
 */
#include <iostream>

using namespace std;

template <typename T>
class Node
{
private:
  T val;
  Node<T> *next;

public:
  T getVal() { return val; }
  Node<T> *getNext() { return next; }
  void setNext(Node<T> *newNext) { next = newNext; }
  Node(T value, Node<T> *nextPtr = nullptr)
  {
    val = value;
    next = nextPtr;
  }
};

template <typename T>
string linkedListStringify(Node<T> *head)
{
  string res = "[ ";

  if (head == nullptr)
  {
    return "[ NULL ]";
  }
  for (Node<T> *ptr = head; ptr != nullptr; ptr = ptr->getNext())
  {
    res.append(to_string(ptr->getVal()));
    if (ptr->getNext() != nullptr)
    {
      res.append(" -> ");
    }
  }

  res.append(" ]");
  return res;
}

string linkedListStringify(Node<string> *head)
{
  string res = "[ ";

  if (head == nullptr)
  {
    return "[ NULL ]";
  }

  for (Node<string> *ptr = head; ptr != nullptr; ptr = ptr->getNext())
  {
    res.append("\"" + ptr->getVal() + "\"");
    if (ptr->getNext() != nullptr)
    {
      res.append(" -> ");
    }
  }

  res.append(" ]");

  return res;
}

class Solution
{
public:
  template <typename T>
  void solve(Node<T> *head)
  {
    cout << "Original list: " << linkedListStringify(head) << endl;

    head = reverseLinkedList(head);

    cout << "Reversed list: " << linkedListStringify(head) << endl;
  }

  template <typename T>
  Node<T> *reverseLinkedList(Node<T> *head)
  {
    Node<T> *prev = nullptr, *next = nullptr, *curr = head;

    while (curr != nullptr)
    {
      next = curr->getNext();
      curr->setNext(prev);
      prev = curr;
      curr = next;
    }

    head = prev;

    return head;
  }
};

int main(void)
{
  Solution solution = Solution();

  Node<string> *str1 = new Node<string>("react");
  Node<string> *str0 = new Node<string>("DREAM", str1);
  Node<string> *headStr = new Node<string>("I am just a guy", str0);

  solution.solve(headStr);

  return 0;
}
