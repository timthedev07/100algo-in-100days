#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
#include <vector>

#include "Helpers.cpp"

using namespace std;

template <typename T>
string arrayStringify(vector<T> arr);
string arrayStringify(vector<string> arr);

template <typename T>
vector<T> sliceArray(vector<T> arr, size_t start, size_t end);
template <typename T>
vector<T> sliceArray(vector<T> arr, size_t start);
#endif
