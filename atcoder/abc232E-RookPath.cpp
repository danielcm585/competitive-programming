#include <iostream>
#include <vector>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

const ll MOD = 998244353;
ll n, m, k, x1, y1, x2, y2;
vector<vector<ll> > memo; 

ll mul(ll a, ll b) {
  a %= MOD, b %= MOD;
  return (a*b)%MOD;
}

void add(ll &a, ll b) {
  a %= MOD, b %= MOD;
  a = (a+b)%MOD;
}

ll dp(int step, int mask) {
  // cout << ">> " << step << " " << mask << endl;
  if (step == 0) return (mask == 3);
  if (memo[step][mask] != -1) return memo[step][mask];
  ll ret = 0;
  if (mask == 0) { // Different row and column
    add(ret, mul((n-2)+(m-2), dp(step-1,0)));
    add(ret, dp(step-1,1));
    add(ret, dp(step-1,2));
  }
  if (mask == 1) { // Same column, different row
    add(ret, mul(m-1, dp(step-1,0)));
    add(ret, mul(n-2, dp(step-1,1)));
    add(ret, dp(step-1,3));
  }
  if (mask == 2) { // Same row, different column
    add(ret, mul(n-1, dp(step-1,0)));
    add(ret, mul(m-2, dp(step-1,2)));
    add(ret, dp(step-1,3));
  }
  if (mask == 3) { // Same row and column
    add(ret, mul(n-1, dp(step-1,1)));
    add(ret, mul(m-1, dp(step-1,2)));
  }
  return memo[step][mask] = ret;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k >> x1 >> y1 >> x2 >> y2;
  memo = vector<vector<ll> >(k+2, vector<ll>(1<<2, -1));
  int curMask = 0;
  if (x1 == x2) curMask |= 2;
  if (y1 == y2) curMask |= 1;
  // cout << ">> " << curMask << '\n';
  cout << dp(k,curMask) << '\n';
  return 0;
}