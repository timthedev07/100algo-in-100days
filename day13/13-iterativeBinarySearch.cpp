/**
 * Day 13 - Iterative binary search
 * 
 * Time complexity: O(log n)
 * But, it has a space complexity of O(1) because it is iterative.
 * 
 * Sorry I didn't have that much time.
 */
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int binSearch(vector<T> arr, T target, int low, int high)
{
  int mid = 0;
  while (high > low)
  {
    mid = ceil((high + low) / 2);

    if (arr[mid] == target)
    {
      return mid;
    }

    if (target <= arr[mid])
    {
      high = mid;
    }
    else if (target > arr[mid])
    {
      low = mid + 1;
    }
  }

  if (arr[low] == target)
  {
    return low;
  }

  return -1;
}

template <typename T>
int binSearch(vector<T> arr, T target)
{
  return binSearch(arr, target, 0, arr.size() - 1);
}

int main(void)
{
  const vector<int> arr0 = {1, 2, 3, 4};
  cout << binSearch<int>(arr0, 2) << endl;
}