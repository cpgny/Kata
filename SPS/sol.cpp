#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll fs(vector<ll> &T, ll m) {
  for(size_t _=0;_<=1;++_) {
    for(size_t q=0;q<T.size();++q) {
      while(T[q]%m>0) {
        ll r=(T[q]%m);
        m=r;
        T[q]=r;
      }
    }
  }
  return *min_element(T.begin(),T.end())*T.size();
};

ll solution(const vector<ll>& arr){
  auto d = arr;
  ll m=*min_element(d.begin(),d.end());
  return fs(d, m);
}
