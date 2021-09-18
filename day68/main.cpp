/**
 * Write a function that reverses a string. The input string is given as an
 * array of characters s.
 */
#include <vector>

using namespace std;

class Solution
{
 public:
  void reverseString(vector<char> &s)
  {
    int n = s.size(), left = 0, right = n - 1;

    while (left < right)
    {
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      left++;
      right--;
    }
  }
};
