コード戦争5Kyuグラフ
#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 18;
int T[N+N]; 

void init(int n) {
    for(int i = 0; i < n; ++i) {
       T[i + N] = 1;
    }
    for(int i = N - 1; i > 0; --i) {
       T[i] = T[i << 1] + T[i << 1 | 1];
    }
}

int lower_bound(int x, int p = 1) {
    while(p < N) {
       if(T[p <<= 1] < x) {
          x -= T[p++];
       }
    }
    return p - N;
}

void update(int p, int v) {
    for(T[p += N] = v; p > 1; p >>= 1) {
       T[p >> 1] = T[p] + T[p ^ 1];
    }
}

vector<int> sol(int n, vector<int> items, int k) {
  init(n);
  vector<int> perm;
  for(int remain = n, pos = 0; remain > 0; --remain) {
       pos += remain + k;
       pos %= remain;
       int p = lower_bound(pos + 1);
       perm.push_back(items[p]);
       update(p, 0);
    }
  return perm;
}

vector < int> josephus(vector < int > items, int k) {
  if(k == 1 || (int) items.size() <= 1) {
      return items;
  }
  vector<int> ans = sol((int) items.size(), items, k - 1);
  return ans;
}
