コード戦争 4Kyu グラフ
#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int QA = 4;
int _,sx, sy, ex, ey;
vector<vector<char>> grid;
vector<vector<int>> dp;

bool query(int a, int b, int c, int d) {
    return a >= 0 && b >= 0 && a < _ && b < _ && grid[a][b] == '.' && (dp[a][b] == -1 || dp[b][a] == dp[c][d] + 1);
}

void bfs() {
  dp[0][0] = 0;
  queue<pair<int, int>> qp;
  qp.push({sx, sy});

  while(!qp.empty()) {
    auto p = qp.front();
    qp.pop();
    for (int i = 0; i < QA; ++i) {
      int qx = p.first + dx[i],
      qy = p.second + dy[i];
      while(query(qx, qy, p.first, p.second)) {
        if(dp[qx][qy] != dp[p.first][p.second] + 1)
          qp.push({qx, qy});
        dp[qx][qy] = dp[p.first][p.second] + 1;
        qx += dx[i];
        qy += dy[i];
      }
    }
  }
}
bool path_finder(string maze) {
  int dm=-1, dd=-1, ds=-1, jx=-1;
  for(int i = 0; i < maze.length(); ++i) {
    ++dm;
    if(maze[i] == '\n')
      break;
  }
  grid.assign(dm, vector<char>(dm));
  dp.assign(dm, vector<int>(dm, -1));
  for(int i = 0; i < maze.length(); ++i) {
    ++dd;
    if((i % (dm+1)) == 0 || (dd % (dm+1)) == 0) {
      ++ds, dd=0;
    }
    grid[ds][dd] = maze[i];
  }
  _=dm,sx=0,sy=0,ex=dm-1,ey=dm-1;
  bfs();
  return dp[ex][ey]>=0;
}
