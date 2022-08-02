#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

int n, m;
vector<vector<int> > a, lfMin, lfMax, rgMin, rgMax;

void precompute() {
  lfMin = lfMax = rgMin = rgMax = vector<vector<int> >(n+2,vector<int>(m+2));
  for (int i = 1; i <= n; i++) {
    lfMin[i][1] = a[i][1];
    lfMax[i][1] = a[i][1];
    for (int j = 2; j <= m; j++) {
      lfMin[i][j] = min(lfMin[i][j-1], a[i][j]);
      lfMax[i][j] = max(lfMax[i][j-1], a[i][j]);
    }
    rgMin[i][m] = a[i][m];
    rgMax[i][m] = a[i][m];
    for (int j = m-1; j >= 1; j--) {
      rgMin[i][j] = min(rgMin[i][j+1], a[i][j]);
      rgMax[i][j] = max(rgMax[i][j+1], a[i][j]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    cin >> n >> m;
    a = vector<vector<int> >(n+2,vector<int>(m+2));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    precompute();
    bool done = 0;
    for (int i = 2; i <= m && !done; i++) {
      // lf: 1..i-1, rg: i..m
      vector<ii> pts;
      for (int j = 1; j <= n; j++) {
        pts.push_back({lfMin[j][i-1],j}); // buka segment
        pts.push_back({lfMax[j][i-1]+1,-j}); // tutup segment
      }
      // lf: blue < red
      // rg: red < blue
      set<ii> bluLf, redRg; // simpan max
      set<ii> redLf, bluRg; // simpan min
      for (int j = 1; j <= n; j++) {
        redLf.insert({lfMin[j][i-1],j});
        redRg.insert({rgMax[j][i],j});
      }
      sort(pts.begin(),pts.end());
      int cntSeg = 0; // banyak segment yg kebuka
      for (auto j : pts) {
        if (j.se > 0) { // buka segment
          cntSeg++;
          // pindahin lf
          redLf.erase({lfMin[j.se][i-1],j.se});
          bluLf.insert({lfMax[j.se][i-1],j.se});
          // pindahin rg
          redRg.erase({rgMax[j.se][i],j.se});
          bluRg.insert({rgMin[j.se][i],j.se});
        }
        else { // tutup segment
          cntSeg--;
        }
        if (cntSeg == 0 && !redLf.empty() && !bluLf.empty()) {
          // cek validity
          int minRedLf = redLf.begin()->fi;
          int maxRedRg = (--redRg.end())->fi;
          int minBluRg = bluRg.begin()->fi;
          int maxBluLf = (--bluLf.end())->fi;
          if (maxBluLf < minRedLf && maxRedRg < minBluRg) {
            cout << "YES\n";
            vector<char> ans(n+2,'R');
            for (auto k : bluLf) ans[k.se] = 'B';
            for (int k = 1; k <= n; k++) cout << ans[k];
            cout << ' ' << i-1 << '\n';
            done = 1;
            break;
          }
        }
      }
    }
    if (!done) cout << "NO\n";
  }
  return 0;
}