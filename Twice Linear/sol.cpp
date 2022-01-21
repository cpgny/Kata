コード戦争4Kyuグラフ
#include <algorithm>
#define rep(i, j) for(int i = 1; i <= j; ++i)

class DoubleLinear
{
public:
    static int dblLinear(int n) {
      int pre = 0, pos = 0;
      std::vector<int> pairs(n+1);
      pairs[0] = 1;
      rep(i, n) {
        pairs[i] = std::min(1+pairs[pre]*2, 1+pairs[pos]*3);
        if(pairs[i] == 2*pairs[pre]+1) pre++;
        if(pairs[i] == 3*pairs[pos]+1) pos++;
      }
      return pairs[n];
    }
};
