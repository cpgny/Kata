コード戦争4Kyuグラフ
#include <bits/stdc++.h>
using namespace std;

bool stp(int q){
    int dp=sqrt(q);
    return (dp*dp==q);
}
int sum_of_squares(int n) {
  if(stp(n)){
    return 1;
  }
  for(int i=1;i<=(int)sqrt(n);++i){
    if(stp(n-(i* i))){
      return 2;
    }
  }
  while(n%4==0){
    n>>=2;
  }
  if(n%8==7){
    return 4;
  }
  return 3;
}
