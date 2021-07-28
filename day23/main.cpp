/**
 *
 * Day 23 - Merge two sorted arrays
 *
 * Time complexity: O(m + n)
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int ptr = nums1.size() - 1;
    m--;
    n--;

    while (ptr >= 0)
    {
      if (n < 0)
      {
        nums1[ptr] = nums1[m];
        m--;
      }
      else if (m < 0)
      {
        nums1[ptr] = nums2[n];
        n--;
      }
      else
      {
        if (nums1[m] > nums2[n])
        {
          nums1[ptr] = nums1[m];
          m--;
        }
        else
        {
          nums1[ptr] = nums2[n];
          n--;
        }
      }

      ptr--;
    }
  }
};
