コード戦争4Kyuグラフ
#include <bits/stdc++.h>
using namespace  std;
vector<int> snail(const vector<vector<int>> &snail_map){
  int _=snail_map.size();
  vector<int> snail;
  int o=99999999;
  if(_==2){snail={snail_map[0][0],snail_map[0][1],snail_map[1][1],snail_map[1][0]};}if(_==1){snail={snail_map[0]};}if(_<1){snail={};}if(_==3){snail={snail_map[0][0],snail_map[0][1],snail_map[0][2],snail_map[1][2],snail_map[2][2],snail_map[2][1],snail_map[2][0],snail_map[1][0],snail_map[1][1]};}
  if(_>=4){
    int N=snail_map.size(),M=snail_map[0].size(),q=2,p=0;
    vector<int> snail_c;
    for(int i=0;i<_;++i)
      for(int j=0;j<_;++j)
        snail_c.push_back(snail_map[i][j]);
    int n=_,t=0;
    float x=_/2.0;
    float k=ceil(x);
    vector<pair<int,int>> s;
    int min=0;if(N%q==0){min=((N*q)>>q)*q;}if(N%q!=0){min=1+((N*q)>>q)*q;}
    if(n%2!=0){t=((k-1)*n)+k;}if(n%2==0){t=(k*n)+k;}
    while(min>=2){
      min-=2;
      ++p;
    }
    vector<int> d;
    for(int i=0;i<p;++i){
      s.push_back(make_pair(i,i));
      s.push_back(make_pair(i,_-1-i));
      s.push_back(make_pair(_-1-i,_-1-i));
      s.push_back(make_pair(_-1-i,i));
    }
    for(size_t a=0;a<1;++a) {
      for(size_t b=0;b<s.size();++b){
        int i=s[b].first,j=s[b].second;
        if(i==s[b+1].first&&j<s[b+1].second){
          while(j<s[b+1].second){
            j++;
            d.push_back(snail_map[i][j-1]);
            d.push_back(snail_map[i][j]);
            d.push_back(o);
          }
        }
        if(i<s[b+1].first&&j==s[b+1].second)
          while(i<s[b+1].first){
            i++;
            d.push_back(snail_map[i][j]);
          }
        if(i==s[b+1].first&&j>s[b+1].second)
          while(j>s[b+1].second){
            --j;
            d.push_back(snail_map[i][j]);
          }
        if(i>s[b+1].first&&j<=s[b+1].second)
          while(i>s[b+1].first){
            --i;
            d.push_back(snail_map[i][j]);
          }
      }
    }
    if(N>3&&N%2!=0){
      d.push_back(snail_c[t-2]);
      d.push_back(snail_c[t-1]);
    }
    for(size_t i=0;i<d.size();++i)
      if(d[i]==o&&d[i-1]==d[i+1])
        d[i-1]=o;
    for(size_t i=0;i<d.size();++i)
      if(d[i]!=o)
        snail.push_back(d[i]);
    snail[snail.size()-1]=snail_c[t-1];
  }
  return snail;
}
