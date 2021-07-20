#include <iostream>
#include <vector>
#include "../helpers/Helpers.h"

using namespace std;

class Solution
{
public:
  template <typename T>
  void solve(vector<T> *arr)
  {
    T *ptr0 = &arr->front();
    T *ptr1 = &arr->back();

    while (ptr0 < ptr1)
    {
      T temp = *ptr0;
      *ptr0 = *ptr1;
      *ptr1 = temp;

      ptr0++;
      ptr1--;
    }
    cout << arrayStringify(*arr) << '\n';
  }

private:
  /* data */
};

int main(void)
{
  Solution solution = Solution();
  vector<int> arr0 = {1, 2, 3, 4, 5};
  vector<string> arr1 = {"plz!", "me", "reverse"};
  solution.solve<int>(&arr0);
  solution.solve<string>(&arr1);
}