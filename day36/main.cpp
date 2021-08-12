/**
 * splits the string into pairs of two characters. If the string contains an odd
 * number of characters then it should replace the missing second character of
 * the final pair with an underscore ('_').
 *
 */
#include <string>
#include <vector>

using namespace std;

vector<string> solution(const std::string &s)
{
  vector<string> res = {};
  int n = s.size();

  for (int i = 0, k = 0; i < n; ++i)
  {
    if (i % 2 == 0)
      res.push_back(string(1, s[i]));
    else
      res[k++].push_back(s.at(i));
  }

  if (n % 2 != 0) res[ceil(n / 2)] += "_";

  return res;
}
