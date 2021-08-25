/**
 * Palindrome Linked List
 * Given the head of a singly linked list, return true if it is a palindrome.
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
  bool isPalindrome(ListNode *head)
  {
    if (!head) return true;

    ListNode *ptr0 = head;
    ListNode *ptr1 = head;

    while (ptr1 && ptr1->next)
    {
      ptr1 = ptr1->next->next;
      ptr0 = ptr0->next;
    }
    ptr1 = head;
    ptr0 = reverseLinkedList(ptr0);

    while (ptr0)
    {
      if (ptr0->val != ptr1->val) return false;
      ptr0 = ptr0->next;
      ptr1 = ptr1->next;
    }

    return true;
  }

  ListNode *reverseLinkedList(ListNode *head)
  {
    ListNode *prev = nullptr, *next = nullptr, *curr = head;

    while (curr != nullptr)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    head = prev;

    return head;
  }
};
