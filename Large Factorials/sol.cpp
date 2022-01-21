コード戦争4Kyuグラフ
#include bits/stdc++.h

#define FOR(i, j) for(unsigned i = 0; i < (j); ++i)
#define FORN(_,n,j) for(int _ = (n); _ <= (j); ++_)
#define MAX 1000
  
std::string factorial(int factorial) {
  if(factorial <= 2) return std::to_string(factorial);

  std::vector<int> res(MAX);
  std::stringstream factor;
  res[0] = 1;
  int prod = 0;

  FORN(i,2,factorial) {
    int c = 0;
    FOR(j,res.size()) {
      int total = res[j]* i + c;
      res[j] = total % 10;
      c = total / 10;
    }
  }
  std::reverse(res.begin(), res.end());

  FOR(i, res.size()) {
    if(res[i] != 0) {
      prod = i;
      break;
    }
  }

  FORN(i,prod,res.size()-1)
    factor << res[i];
  
  std::string ans = factor.str();
  return ans;
}
