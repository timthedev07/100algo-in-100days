/**
 *
 * Day 37 - Rotate a matrix of dimensions n * n 90deg clockwise
 *
 * Time complexity: O(???)
 */
#include <iostream>
#include <vector>

#include "../helpers/Helpers.h"

using namespace std;

class Solution
{
 public:
  void rotateMatrix(vector<vector<int>> &mat)
  {
    cout << "Original matrix:\n" << matrixStringify(mat) << '\n';

    int n = mat.size();
    // step 1 = transpose array
    for (int k = 0; k < n - 1; ++k)
    {
      int rowJ = k, colI = k;
      while (rowJ < n)
      {
        swap(&(mat[colI][k]), &(mat[k][rowJ]));
        rowJ++;
        colI++;
      }
    }

    int m = floor(n / 2);

    // step 2 = flip horizontally
    for (int i = 0; i < n; ++i)
    {
      for (int a = 0, b = n - 1; a < m; ++a, --b)
      {
        swap(&(mat[i][a]), &(mat[i][b]));
      }
    }

    cout << "Rotated matrix:\n" << matrixStringify(mat) << '\n';
  };

 private:
  void swap(int *a, int *b)
  {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }
};

int main(void)
{
  Solution solution = Solution();
  vector<vector<int>> mat0 = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int>> mat1 = {{1, 2, 3, 4, 5},
                              {6, 7, 8, 9, 10},
                              {11, 12, 13, 14, 15},
                              {16, 17, 18, 19, 20},
                              {21, 22, 23, 24, 25}};

  solution.rotateMatrix(mat0);
  solution.rotateMatrix(mat1);
}
