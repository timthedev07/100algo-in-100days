/**
  The Tribonacci sequence Tn is defined as follows:

  T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

  Given n, return the value of Tn.

 */
class Solution
{
 public:
  int tribonacci(int n)
  {
    if (n <= 1) return n;
    int table[n + 1];
    table[0] = 0;
    table[1] = 1;
    table[2] = 1;

    for (int i = 3; i <= n; ++i)
    {
      table[i] = table[i - 1] + table[i - 2] + table[i - 3];
    }

    return table[n];
  }
};
