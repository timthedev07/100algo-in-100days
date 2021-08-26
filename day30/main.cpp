/**
 * Day 29 - firstNotRepeatingCharacter (codesignal)
 * Given a string s consisting of small English letters
 * find and return the first instance of a non-repeating character in it. If
 * there is no such character, return '_'.
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
 public:
  char firstNotRepeatingCharacter(string s)
  {
    unordered_map<char, int> map;

    for (const char &c : s)
    {
      if (map.count(c))
        map[c] = 0;
      else
        map[c]++;
    }

    for (const char &c : s)
    {
      if (map[c] == 1) return c;
    }

    return '_';
  }
};
int main(void) {}
