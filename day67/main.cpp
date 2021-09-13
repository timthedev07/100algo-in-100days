/**
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
 public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> table;

    for (char &c : s)
    {
      if (table.count(c))
      {
        table[c]++;
      }
      else
        table.insert(pair<char, int>(c, 1));
    }

    for (char &c : t)
    {
      if (!table.count(c) || table[c] == 0) return false;
      table[c]--;
    }

    return true;
  }
};
