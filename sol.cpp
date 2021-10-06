#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+5;

template<typename T> void mx(T &x,T y) {
  x = max(x, y);
};

bool froc(pair<int,int>p) {
  return p.first==0||p.second==0;
};

string lcs(const string& x, const string& y)
{
  vector<vector<pair<int, pair<int,int>>>> dp(x.length()+1,
  vector<pair<int,pair<int,int>>>(y.length()+1,{-INF,{0,0}}));
  dp[0][0] = {0,{0,0}};
  for(int _=0;_<x.length();++_) {
    for(int o=0;o<y.length();++o) {
      if(x[_]==y[o]) {
        mx(dp[_+1][o+1],make_pair(dp[_][o].first+1,make_pair(_,o)));
      }
        mx(dp[_+1][o],make_pair(dp[_][o].first,make_pair(_,o)));
        mx(dp[_][o+1],make_pair(dp[_][o].first,make_pair(_,o)));
    }
  }
  pair<int,pair<int,int>>ans={0,{0,0}};
  for(int _=0;_<=x.length();++_) {
    for(int l=0;l<=y.length();++l) {
      mx(ans,make_pair(dp[_][l].first,make_pair(_,l)));
    }
  }
  string s;
  pair<int,int>c=ans.second;
  while(!froc(c)) {
    int _=c.first;
    int p=c.second;
    pair<int,int>q=dp[_][p].second;
    if(q==make_pair(_-1,p-1)) {
      assert(x[_-1]==y[p-1]);
      s+=x[_-1];
    }
    c=q;
  }
  reverse(s.begin(),s.end());
  return s;
}
