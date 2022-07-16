#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

int n, m;
vector<int> dr = {-1,0,1,0};
vector<int> dc = {0,1,0,-1};
vector<vector<int>> a;
// vector<vector<bool>> vis;
vector<vector<int>> dis;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  a = vector<vector<int>>(n+2,vector<int>(m+2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  queue<ii> q;
  dis = vector<vector<int>>(n+2,vector<int>(m+2,-1));
  q.push({1,1}); dis[1][1] = 0;
  while (!q.empty()) {
    ii cur = q.front(); q.pop();
    int r = cur.fi;
    int c = cur.se;
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (dis[nr][nc] == -1) {
        dis[nr][nc] = dis[r][c] + 1;
        q.push({nr,nc});
      }
    }
  }
  return 0;
}