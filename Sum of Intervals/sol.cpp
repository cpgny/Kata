コード戦争4Kyuグラフ
#include <bits/stdc++.h>

using namespace std;

int sum_intervals(vector<pair<int, int>> intervals) {
  int ans = 0;
  sort(intervals.begin(), intervals.end());
  intervals.push_back(make_pair(0, 0));
  for(int i = 0; i < (int) intervals.size(); ++i) {
    if(intervals[i].first <= intervals[i + 1].first && 
       intervals[i].second >= intervals[i + 1].first && 
       intervals[i].second <= intervals[i + 1].second) {
       intervals[i + 1].first = intervals[i].first;
    }
    else if(intervals[i].first <= intervals[i + 1].first && intervals[i].second >= intervals[i + 1].first
            && intervals[i].second >= intervals[i + 1].second) {
      intervals[i + 1].first = intervals[i].first, intervals[i + 1].second = intervals[i].second;
       }
    }
    intervals.push_back(make_pair(0, 0));
    for(int i = 0; i < (int) intervals.size(); ++i) {
       if(intervals[i].first != intervals[i + 1].first) {
           ans += abs(intervals[i].first - intervals[i].second);
       }
    }
    return ans; 
}

