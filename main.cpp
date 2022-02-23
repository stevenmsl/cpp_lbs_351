#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol351;

/*
Input: m = 5, n = 7
Output: 10680
*/
tuple<int, int, int>
testFixture1()
{
  return make_tuple(5, 7, 106080);
}

/*
Input: m = 1, n = 1
Output: 9
*/
tuple<int, int, int>
testFixture2()
{
  return make_tuple(1, 1, 9);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  auto result = sol.countPatterns(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  auto result = sol.countPatterns(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}