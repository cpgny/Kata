コード戦争3Kyuグラフ
#include <bits/stdc++.h>
using namespace std;

bool validate_battlefield(vector<vector<int>> field) {
  int n = 0;
  vector<int> d={1,1,1,1,2,2,2,3,3,4};
  vector<int> cache;
  vector<vector<int>> m(field.size()+2,vector<int>(field.size()+2));
  vector<int> l;
  for(int i=2;i<m.size();++i)
    for(int j=2;j< m[i].size();++j)
      m[i][j] = field[i-2][j-2];
  for(int i = 0; i < m.size(); ++i)
    for(int j = 0; j < m[i].size(); ++j)
      l.push_back(m[i][j]);
  for(size_t i=0;i<l.size();++i) {
    if(l[i]==1&&l[i+1]==1&&l[i-m.size()+2]!=1&&l[i+m.size()+2]!=1) {
      int d = 0;
      for(size_t j=i;j%m.size()!=0;j++) {
        while(l[j]==1) {
          d++;
          l[j]=3;
          break;
        }
      }
      cache.push_back(d);
    }
    if(l[i]==1&&l[i+1]!=1&&l[i-1]!=1) {
      int d = 0;
      for(size_t k=i;k<l.size();k+=m.size()+2) {
        while(l[k]==1) {
          d++;
          l[k]=2;
          break;
        }
      }
      cache.push_back(d);
    }
  }
  sort(cache.begin(), cache.end());
  return cache==d?true:false;
}
