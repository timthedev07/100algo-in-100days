/**
 * Day 7 - Quick sort
 *
 * Time complexity: O(n^2) in the worst case && O(n log n) on average
 */
#include <iostream>
#include <vector>

#include "../helpers/Helpers.h"

using namespace std;

class Solution
{
public:
  template <typename T>
  void solve(vector<T> arr)
  {
    cout << "Original array: " << arrayStringify(arr) << endl;
    cout << "Sorted array: " << arrayStringify(quickSort(arr)) << endl;
  }

private:
  template <typename T>
  void swap(T *a, T *b)
  {
    T tmp = *a;
    *a = *b;
    *b = tmp;
  }

  template <typename T>
  vector<T> quickSort(vector<T> arr)
  {
    quickSort(&arr, 0, arr.size() - 0);
    return arr;
  }

  template <typename T>
  void quickSort(vector<T> *arr, size_t low, size_t high)
  {
    size_t j = 0;

    if (low < high)
    {
      j = partition(arr, low, high);
      quickSort(arr, low, j);
      quickSort(arr, j + 1, high);
    }
  }

  template <typename T>
  size_t partition(vector<T> *arr, size_t low, size_t high)
  {
    // pick a pivot
    T pivot = (*arr)[low];

    // define i to be the pointer that starts traversing from the arr[low]
    // and j to be the pointer that starts traversing from arr[high]
    size_t i = low, j = high, size = arr->size();

    while (i < j)
    {
      // increment index i until finding an element larger than the pivot
      do
      {
        i++;
      } while ((*arr)[i] <= pivot && i < size);

      // decrement index j until finding an element smaller or equal to the
      // pivot
      do
      {
        j--;
      } while ((*arr)[j] > pivot && j >= 0);

      // swap the two elements
      if (i < j)
      {
        swap(&((*arr)[i]), &((*arr)[j]));
      }
    }
    // put the pivot at the place where j stopped traversing
    // such that now all elements on the right side of the pivot is larger and
    // all the other ones on the left is smaller
    swap(&((*arr)[low]), &((*arr)[j]));

    return j;
  }
};

int main(void)
{
  Solution solution = Solution();
  const vector<string> arr0 = {"n log n!", "It", "Hey!", "is"};
  solution.solve(arr0);
}
