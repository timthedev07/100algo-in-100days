/**
 * Day 11: Recursive linear search
 *
 * Note: I didn't have that much time so I just did this.
 */
#include <iostream>
#include <vector>

using namespace std;

bool recurLin(vector<int> arr, int target, int start, int end)
{
  if (start > end)
  {
    return false;
  }
  if (arr[start] == target)
  {
    return true;
  }
  return recurLin(arr, target, start + 1, end);
}

bool recurLin(vector<int> arr, int target)
{
  return recurLin(arr, target, 0, arr.size() - 1);
};

int main(void)
{
  vector<int> arr0 = {1, 2, 3, 4, 5};
  cout << (recurLin(arr0, 3) ? "found" : "not found") << endl;
  cout << (recurLin(arr0, 1) ? "found" : "not found") << endl;
  cout << (recurLin(arr0, 5) ? "found" : "not found") << endl;
  cout << (recurLin(arr0, 6) ? "found" : "not found") << endl;
}
