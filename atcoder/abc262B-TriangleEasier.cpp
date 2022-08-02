#include <iostream>
#include <vector>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

int n, m;
vector<vector<bool> > adj;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  vector<vector<bool> > adj(n+2, vector<bool>(m+2));
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i+1; j <= n; j++) {
      for (int k = j+1; k <= n; k++) {
        ans += adj[i][j] && adj[j][k] && adj[k][i];
      }
    }
  }
  cout << ans << '\n';
  return 0;
}