#include <iostream>
#include <queue>
#include <map>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

int n, k;
vector<int> start;

void reverse(vector<int> &v, int l, int len) {
  int r = l+len-1;
  for (; l < r; l++, r--) swap(v[l],v[r]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  start = vector<int>(n);
  for (int i = 0; i < n; i++) cin >> start[i];
  cin >> k;
  queue<vector<int>> q;
  map<vector<int>,int> dis;
  q.push(start); dis[start] = 0;
  while (!q.empty()) {
    vector<int> cur = q.front(); q.pop();
    for (int i = 0; i < n-k+1; i++) {
      vector<int> nx = cur;
      reverse(nx,i,k);
      if (!dis.count(nx)) { 
        // for (auto j : cur) cout << j << ' ';
        // cout << " -> ";
        // for (auto j : nx) cout << j << ' ';
        // cout << '\n';
        dis[nx] = dis[cur]+1;
        q.push(nx);
      }
    }
  }
  vector<int> sorted;
  for (int i = 0; i < n; i++) sorted.push_back(i+1);
  if (dis.count(sorted)) cout << dis[sorted] << '\n';
  else cout << "-1\n";
  return 0;
}