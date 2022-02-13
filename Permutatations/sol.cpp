#include <bits/stdc++.h>

using namespace std;

vector<string> permutations(string s) {
  vector<string> perms;
  sort(s.begin(), s.end());
  do {
    perms.push_back(s);
  }
  while(next_permutation(s.begin(), s.end()));
  perms.erase(unique(perms.begin(),perms.end()),perms.end());
  return perms;
}
