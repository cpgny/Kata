#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define rep(i, j) for(unsigned int i = 0; i < j; ++i)
#define pb push_back
#define MAX 1000
  
std::string factorial(int factorial) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  if(factorial <= 2) return std::to_string(factorial);

  std::vector<int> res(MAX);
  std::stringstream factor;
  res[0] = 1;
  int prod = 0;

  for(int i = 2; i <= factorial; ++i) {
    int c = 0;
    for(unsigned int j = 0; j < res.size(); ++j) {
      int total = res[j]* i + c;
      res[j] = total % 10;
      c = total / 10;
    }
  }

  std::reverse(res.begin(), res.end());

  rep(i, res.size()) {
    if(res[i] != 0) {
      prod = i;
      break;
    }
  }

  for(unsigned int i = prod; i < res.size(); ++i)
    factor << res[i];
  
  std::string ans = factor.str();
  
  return ans;
}
