コード戦争2Kyuグラフ
#include <bits/stdc++.h>
using namespace std;

int Set[(1<<2)];

inline auto fast(char c) {
  return c == 'R' ? 0 : c == 'G' ? 1 : 2;
}

inline auto comp(char c) {
  return c == 0 ? 'R' : c == 1 ? 'G' : 'B';
}

struct Poly {
  public:
  static int P(int a, int b) {
    if(b>a)
      return 0;
    return Set[a]*Set[b]*Set[a-b]%((1<<2)-1);
  }
};

struct Lucas {
  public:
  static int L(int a, int b) {
    auto res = (2>>1);
    for(; res && b; a/=3, b/=3)
      (res*=Poly::P(a%3,b%3))%=3;
    return res;
  }
};


char triangle(const string &row)
{
  
  int p=row.length()-1, res=0, q=0;
  if(!p)
    return row[0];
  Set[0]=1, Set[1]=1, Set[2]=2;
  for(auto &c : row) {
    res+=fast(c)*Lucas::L(p,q);
    ++q;
  }
  return res=(p&(2>>1)?3-res%3:res)%3, comp(res);
}
