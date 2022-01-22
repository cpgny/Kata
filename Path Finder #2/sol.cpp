コード戦争4Kyuグラフ
#include <bits/stdc++.h>
using namespace std;
class Query {
public:
    int r;
    int c;
    int d;
    Query(int a, int b, int c)
        : r(a), c(b), d(c) {}
};
int bfs(vector<vector<char>> grid, int xy)
{
    Query yx(0, 0, 0);
    bool dp[xy][xy];
    for (int jx=0; jx < xy; ++jx) {
        for (int xj=0; xj < xy; ++xj)
        {
            if (grid[jx][xj] == 'W')
                dp[jx][xj] = true;
            else
                dp[jx][xj] = false;
            if (grid[jx][xj] == 's')
            {
               yx.r = jx;
               yx.c = xj;
            }
        }
    }
    queue<Query> qp;
    qp.push(yx);
    dp[yx.r][yx.c] = true;
    while (!qp.empty()) {
        Query p = qp.front();
        qp.pop();
        if (grid[p.r][p.c] == 'e') return p.d;
        if (p.r - 1 >= 0 &&
            dp[p.r - 1][p.c] == false) {
            qp.push(Query(p.r - 1, p.c, p.d + 1));
            dp[p.r - 1][p.c] = true;
        }
        if (p.r + 1 < xy &&
            dp[p.r + 1][p.c] == false) {
            qp.push(Query(p.r + 1, p.c, p.d + 1));
            dp[p.r + 1][p.c] = true;
        }
        if (p.c - 1 >= 0 &&
            dp[p.r][p.c - 1] == false) {
            qp.push(Query(p.r, p.c - 1, p.d + 1));
            dp[p.r][p.c - 1] = true;
        }
        if (p.c + 1 < xy &&
            dp[p.r][p.c + 1] == false) {
            qp.push(Query(p.r, p.c + 1, p.d + 1));
            dp[p.r][p.c + 1] = true;
        }
    }
    return -1;
}

int path_finder(string maze) {
  if(maze.length()==1) return 0;
  int dm=-1, dd=-1, ds=-1, jx=-1;
  for(int i = 0; i < maze.length(); ++i) {
    ++dm;
    if(maze[i] == '\n')
      break;
  }
  vector<vector<char>> grid(dm, vector<char>(dm));
  for(int i = 0; i < maze.length(); ++i) {
    ++dd;
    if((i % (dm+1)) == 0 || (dd % (dm+1)) == 0) {
      ++ds, dd=0;
    }
    grid[ds][dd] = maze[i];
  }
  grid[0][0]='s';
  grid[dm-1][dm-1]='e';
  return bfs(grid, dm);
}
