#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol351
{

  class Solution
  {
  private:
    /* use as 1-based */
    vector<vector<int>> jumps = vector<vector<int>>(10, vector<int>(10, 0));

  public:
    int countPatterns(int m, int n);
    Solution();
  };
}
#endif