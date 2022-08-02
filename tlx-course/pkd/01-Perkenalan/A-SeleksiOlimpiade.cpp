#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int tc; cin >> tc;
  while (tc--) {
    int n, m; cin >> n >> m;
    string x; cin >> x;
    
    int x_idx;
    int a[n][3+2];
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      for (int j = 1; j <= 3; j++) cin >> a[i][j];
      if (s == x) x_idx = i;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (sesi 1 unggul) cnt++;
      else if (sesi 1 sama && sesi 2 unggul) cnt++;
      else if (sesi 1 sama && sesi 2 sama && sesi 3 unggul) cnt++;
    }

    int x_rank = cnt+1;
    if (x_rank <= m) cout << "YA\n";
    else cout << "TIDAK\n";
  }
  return 0;
}