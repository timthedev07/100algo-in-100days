
#include "Helpers.h"

#include <iostream>
#include <vector>

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
    res.append(to_string(arr.at(i)));
    if (i != n - 1)
    {
      res.append(", ");
    }
  }
  res.append(" ]");

  return res;
}

// string overload
string arrayStringify(vector<string> arr)
{
  if (arr.empty())
  {
    return "[  ]";
  }
  string res = "[ ";

  for (size_t i = 0, n = arr.size(); i < n; ++i)
  {
    res.append("\"" + (arr.at(i)) + "\"");
    if (i != n - 1)
    {
      res.append(", ");
    }
  }
  res.append(" ]");

  return res;
};

template <typename T>
vector<T> sliceArray(vector<T> arr, size_t start, size_t end)
{
  vector<T> res = vector<T>(arr.begin() + start, arr.begin() + (end - start));
  return res;
}

template <typename T>
vector<T> sliceArray(vector<T> arr, size_t start)
{
  vector<T> res = vector<T>(arr.begin() + start, arr.end());
  return res;
}
