#include <iostream>

using namespace std;

/**
  Definition for singly-linked list.
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    if (l1 == nullptr && l2 == nullptr)
    {
      return nullptr;
    }

    // true => start with l1
    // false => start with l2
    int h = l1 != nullptr && l2 != nullptr ? l1->val < l2->val
            : l1 != nullptr                ? true
                                           : false;

    ListNode *res = new ListNode(h ? l1->val : l2->val);
    ListNode *head = res;
    ListNode *ptr0 = l1;
    ListNode *ptr1 = l2;

    if (h)
      ptr0 = ptr0->next;
    else
      ptr1 = ptr1->next;

    while (ptr0 != nullptr && ptr1 != nullptr)
    {
      if (ptr0->val < ptr1->val)
      {
        res->next = ptr0;
        ptr0 = ptr0->next;
      }
      else if (ptr0->val >= ptr1->val)
      {
        res->next = ptr1;
        ptr1 = ptr1->next;
      }
      res = res->next;
    }

    if (ptr0 != nullptr)
    {
      res->next = ptr0;
    }
    if (ptr1 != nullptr)
    {
      res->next = ptr1;
    }

    return head;
  }
};
