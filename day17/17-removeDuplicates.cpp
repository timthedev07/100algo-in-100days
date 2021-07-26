/**
 * Day 17 - Remove duplicates from sorted array (leet code)
 *
 *
 * Given an integer array nums sorted in non-decreasing order, remove some
 * duplicates in-place such that each unique element appears at most twice. The
 * relative order of the elements should be kept the same.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void) {}

class Solution
{
 public:
  int removeDuplicates(vector<int> &nums)
  {
    // use a hashmap to keep track of how many duplicates
    // there are for each value.
    unordered_map<int, int> record = {};

    int n = nums.size();
    int res = n;
    vector<int>::iterator it = nums.begin();

    while (it != nums.end())
    {
      if (record.find(*it) != record.end())
      {
        if (record[*it] >= 2)
        {
          nums.erase(it);
          res--;
        }
        else
        {
          cout << record[*it] << endl;
          record[*it]++;
          ++it;
        }
      }
      else
      {
        record.insert(pair<int, int>(*it, 1));
        ++it;
      }
    }

    return res;
  }
};
