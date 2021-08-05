/**
 *
 * Day 31 - implement strStr function - LeetCode
 *
 * This is a brute force two pointer solution, it sucks.
 */
#include <iostream>

using namespace std;

class Solution
{
 public:
  int strStr(string haystack, string needle)
  {
    if (needle.empty())
    {
      return 0;
    }
    if (haystack.empty())
    {
      return -1;
    }
    if (haystack.size() < needle.size())
    {
      return -1;
    }
    int ptr0 = 0;
    int ptr1 = 0;
    int i = 0;
    int n = haystack.size();
    int m = needle.size();

    while (ptr0 < n && ptr1 < m)
    {
      if (haystack[ptr0] == needle[ptr1])
      {
        if (ptr1 == m - 1)
        {
          return i;
        }
        ptr0++;
        ptr1++;
      }
      else
      {
        ptr1 = 0;
        i++;
        ptr0 = i;
      }

      if (i == n)
      {
        break;
      }
    }
    return -1;
  }
};

int main(void) {}
