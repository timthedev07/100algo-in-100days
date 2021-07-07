#include <iostream>
#include <vector>

#include "helpersModule.h"

using namespace std;

template <typename T>

string arrayStringify(vector<T> arr)
{
  if (arr.empty())
  {
    return "[  ]";
  }
  string res = "[ ";

  for (size_t i = 0, n = arr.size(); i < n; ++i)
  {
    res.append("" + (arr.at(i)));
    if (i != n - 1)
    {
      res.append(", ");
    }
  }
  res.append(" ]");

  return res;
}
