コード戦争4Kyuグラフ
#include <bits/stdc++.h>
using namespace std;
string range_extraction(vector<int> args) {
  args.push_back(o); //999999
  vector<int> p;
  vector<int> q;
  vector<pair<int,int>> d;
  string ans;
  for(size_t i=0;i<args.size();++i) {
    if(args[i]+1==args[i+1]&&args[i]-1==args[i-1]){
      p.push_back(args[i]);
    }
  }
  for(size_t i=0;i<args.size();++i){
    for(int j=0;j<p.size();++j){
      if(args[i]==p[j]){
        args[i]=n; //99999
      }
      if(args[i]!=n){q.push_back(args[i]);;}
    }
  }
  for(int i=0;i<args.size();++i) {
    if(args[i]!=n&&args[i+1]!=n){
      d.push_back(make_pair(args[i],m)); //9999
    }
    if(args[i]!=n&&args[i+1]==n){
      for(int j=i+1;j<args.size();++j) {
        if(args[j]!=n){
          d.push_back(make_pair(args[i],args[j]));
          break;
        }
      }
    }
  }
  for(int i = 0; i < d.size(); ++i) {
    if(d[i].first == d[i-1].second){d[i].first=m;}
  }
  for(int i = 0; i < d.size(); ++i){
    if(d[i].first != m && d[i].second == m){
      ans+=to_string(d[i].first)+',';
    }
    else if(d[i].first != m && d[i].second != m){
      ans+=to_string(d[i].first)+'-'+to_string(d[i].second)+',';
    }
    else if(d[i].first==o){
      ans+='!';
    }
  }
  return ans.substr(0,ans.length()-8);
}
