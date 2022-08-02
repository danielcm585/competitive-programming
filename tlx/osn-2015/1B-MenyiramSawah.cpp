#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<pair<int,int>,int> iii;

int n, m, q;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
string osn;
vector<vector<int> > a;
vector<vector<vector<int> > > pref;
map<string,int> dir = {
  {"URDL", 15},
  {"RDL", 14},
  {"UDL", 13},
  {"URL", 11},
  {"URD", 7},
  {"RD", 6},
  {"DL", 12},
  {"UR", 3},
  {"UL", 9},
  {"U", 1},
  {"R", 2},
  {"D", 4},
  {"L", 8}
};

bool inRange(int r, int c, int A, int B, int C, int D) {
  return A <= r && r <= C && B <= c && c <= D;
}

bool isGood(int r, int c, int mask, int A, int B, int C, int D) {
  for (int i = 0; i < 4; i++) {
    if ((mask>>i)&1^1) continue;
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (inRange(nr,nc,A,B,C,D) && a[r][c] < a[nr][nc]) return 0;
  }
  return 1;
}

void buildPref() {
  pref = vector<vector<vector<int> > >(16,vector<vector<int> >(n+2,vector<int>(m+2)));
  // pref[mask][r][c] = sumOf(isGood(1,1)...isGood(r,c))
  for (auto k : dir) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int mask = k.se;
        pref[mask][i][j] = pref[mask][i-1][j] + pref[mask][i][j-1] - pref[mask][i-1][j-1] + isGood(i,j,mask,1,1,n,m);
      }
    }
  }
}

int getPref(int mask, int A, int B, int C, int D) {
  if (A > C || B > D) return 0;
  return pref[mask][C][D] - pref[mask][A-1][D] - pref[mask][C][B-1] + pref[mask][A-1][B-1];
}

int getSum(int A, int B, int C, int D) {
  int middle = getPref(dir["URDL"],A+1,B+1,C-1,D-1);
  int uFrame = getPref(dir["RDL"],A,B+1,A,D-1);
  int rFrame = getPref(dir["UDL"],A+1,D,C-1,D);
  int dFrame = getPref(dir["URL"],C,B+1,C,D-1);
  int lFrame = getPref(dir["URD"],A+1,B,C-1,B);
  int ulCorner = isGood(A,B,dir["RD"],A,B,C,D);
  int urCorner = isGood(A,D,dir["DL"],A,B,C,D);
  int dlCorner = isGood(C,B,dir["UR"],A,B,C,D);
  int drCorner = isGood(C,D,dir["UL"],A,B,C,D);
    
  int total = middle + uFrame + rFrame + dFrame + lFrame;
  set<iii> st;
  st.insert({{A,B},ulCorner});
  st.insert({{A,D},urCorner});
  st.insert({{C,B},dlCorner});
  st.insert({{C,D},drCorner});
  for (auto i : st) total += i.se;

  return total;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> osn;
  cin >> n >> m >> q;
  a = vector<vector<int> >(n+2,vector<int>(m+2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  buildPref();
  while (q--) {
    int A, B, C, D; cin >> A >> B >> C >> D;
    if (getSum(A,B,C,D) != -1) cout << "Tidak Mungkin\n";
    else {
      if (isGood(A,B,dir["RD"],A,B,C,D)) cout << "Kiri Atas\n";
      else if (isGood(C,D,dir["UL"],A,B,C,D)) cout << "Kanan Bawah\n";
      else cout << "Tidak Mungkin\n";
    }
  }
  return 0;
}