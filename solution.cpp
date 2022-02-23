#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol351;
using namespace std;

/*takeaways
  - if you know there is symmetry between patterns then you can optimize
    the solution
    - starting from 1,3,7, or 9 are the same in terms of the number of
      patterns each can generated
      - 1->2->3->4 is symmetric to 3->2->1->6
        - don't forget going from 3 to 4 (or 1 to 6) is a legit move
    - same for starting from 2,4,6 or 8
  - visiting the keys
    - once you done visiting this path: 1 -> 2 -> ...
      you need to reset 2 to unvisited so it won't
      interfering with the next path: 1 -> 3 -> ...
*/

int Solution::countPatterns(int m, int n)
{
  auto total = 0;
  /* so we can operate as 1-based instead of 0-based */
  auto visited = vector<int>(10, false);

  function<int(int, int, int)> visit = [&](int start, int len, int count)
  {
    /*
      - don't forget count starts with 0 and len starts with one
    */
    if (len >= m)
      count++;
    /*
      - check if we need to visit the next key, which the length
        will be increased by one
    */
    len++;
    if (len > n)
      return count;

    visited[start] = true;
    for (auto next = 1; next <= 9; next++)
    {
      auto jump = jumps[start][next];
      /*
         - if there is a jump in-between the start and the next,
           you can continue only if the jump has been visited
      */
      if (!visited[next] && (!jump || visited[jump]))
        count = visit(next, len, count);
    }

    /*
      - done with exploring this path
      - reset it so the caller can start
        a new path without being interfered
    */
    visited[start] = false;

    return count;
  };

  total += visit(1, 1, 0) * 4;
  total += visit(2, 1, 0) * 4;
  total += visit(5, 1, 0);

  return total;
}

Solution::Solution()
{
  jumps[1][3] = jumps[3][1] = 2;
  jumps[4][6] = jumps[6][4] = 5;
  jumps[7][9] = jumps[9][7] = 8;
  jumps[1][7] = jumps[7][1] = 4;
  jumps[2][8] = jumps[8][2] = 5;
  jumps[3][9] = jumps[9][3] = 6;
  jumps[1][9] = jumps[9][1] =
      jumps[3][7] = jumps[7][3] = 5;
}