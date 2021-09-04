/**
 *
  You are given two non-empty linked lists representing two non-negative
 integers. The digits are stored in reverse order, and each of their nodes
 contains a single digit. Add the two numbers and return the sum as a linked
 list.

    You may assume the two numbers do not contain any leading zero, except the
  number 0 itself.

Examples:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    // new head for the result list
    ListNode *dummyHead = new ListNode();
    ListNode *ptr3 = dummyHead;

    // pointers for traversing l1 and l2
    ListNode *ptr1 = l1;
    ListNode *ptr2 = l2;

    // carry, 1 if the current two digits sum to a number that's greater than
    // 10, meaning we have to add 1 to to the next sum, and 0 means the sum is
    // less than 10 and we are good
    int carry = 0;

    while (ptr1 || ptr2)
    {
      // sum the two digits stored in each pointer, and if any of them
      // is nullptr, just use 0 so it won't affect the sum,
      // and also include the carry, which would be one if the last sum is
      // greater than 10(like we learned in elementary school)
      int value = (ptr1 ? ptr1->val : 0) + (ptr2 ? ptr2->val : 0) + carry;

      // update the carry
      if (value > 9)
        carry = 1;
      else
        carry = 0;

      // create the new node with the new digit
      ListNode *newNode = new ListNode(value % 10);

      // slap that new node to the end the result list
      ptr3->next = newNode;

      // traverse
      ptr1 = ptr1 ? ptr1->next : ptr1;
      ptr2 = ptr2 ? ptr2->next : ptr2;
      ptr3 = newNode;
    }

    // finally, if the carry is still one, like in here:
    // l1 = [9,9]
    // l2 = [1]
    // res = [001]
    //
    // without this step it would be
    // res = [00]
    if (carry == 1)
    {
      // slap a one at the end
      ListNode *lastNode = new ListNode(1);
      ptr3->next = lastNode;
    }

    // return the next of dummyHead since dummyHead is just a meaningless and
    // dummy pointer
    return dummyHead->next;
  }
};
