#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

int n, m;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
vector<vector<char> > a;
vector<vector<bool> > vis;

bool valid(int r, int c) {
  return 1 <= r && r <= n && 1 <= c && c <= m;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    cin >> n >> m;
    a = vector<vector<char> >(n+2, vector<char>(m+2));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] != 'B') continue;
        for (int k = 0; k < 4; k++) {
          int r = i+dr[k], c = j+dc[k];
          if (valid(r,c) && a[r][c] == '.') a[r][c] = '#';
        }
      }
    }
    vis = vector<vector<bool> >(n+2, vector<bool>(m+2));
    queue<ii> q; q.push(ii(n,m)); 
    vis[n][m] = 1;
    while (!q.empty()) {
      ii cur = q.front(); q.pop();
      int r = cur.fi, c = cur.se;
      if (a[r][c] == '#') continue;
      for (int i = 0; i < 4; i++) {
        int nr = r+dr[i], nc = c+dc[i];
        if (!valid(nr,nc) || vis[nr][nc]) continue;
        if (a[nr][nc] != '#') {
          vis[nr][nc] = 1;
          q.push(ii(nr,nc));
        }
      }
    }
    bool good = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        // cout << vis[i][j];
        if (a[i][j] == 'G' && !vis[i][j]) good = 0;
        if (a[i][j] == 'B' && vis[i][j]) good = 0;
      }
      // cout << '\n';
    }
    cout << (good ? "Yes" : "No") << '\n';
  }
  return 0;
}