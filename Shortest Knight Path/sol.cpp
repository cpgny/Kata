コード戦争4Kyuグラフ
#include <bits/stdc++.h>
using namespace std;

struct point {
   int xy, jy, py;
};

const int dx[8][2] = { -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1 }; 
int dp[10][10];
char c_val[5], x_val[5];

bool query(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n && dp[x][y] == 0;
}

int bfs() {
    queue<point> q;
    point qp, pq;
    qp.xy = x_val[0]-'a';
    qp.jy = x_val[1]-'1';
    qp.py = 0;
    int jx = c_val[0]-'a', xj = c_val[1]-'1';
    memset(dp, 0, sizeof(dp));
    dp[qp.xy][qp.jy] = 1;
    q.push(qp);
          
    while(!q.empty()) {
       qp = q.front();
       q.pop();
       if(qp.xy == jx && qp.jy == xj) {
           return qp.py;
       }
       for(int i = 0; i < 8; ++i) {
           pq.xy = qp.xy + dx[i][0];
           pq.jy = qp.jy + dx[i][1];
           pq.py = qp.py+1;
           if(pq.xy == jx && pq.jy == xj) {
              return pq.py;
           }
           while(query(pq.xy, pq.jy, 8)) {
              dp[pq.xy][pq.jy] = 1;
              q.push(pq);
           }
       }
    }
    return 0;
}

                  
int knight(string start, string finish) {
    for(int i = 0; i < (int) start.length(); ++i) x_val[i] = start[i], c_val[i] = finish[i];
    return bfs();
}
