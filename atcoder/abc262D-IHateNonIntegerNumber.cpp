#include <iostream>
#include <vector>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

const ll MOD = 998244353;
int n;
vector<int> a;
vector<vector<vector<int> > > dp;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  a = vector<int>(n+2);
  for (int i = 1; i <= n; i++) cin >> a[i];
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    // dp[j][k][l]: di index-j, ambil sebanyak k, sum%i = l
    dp = vector<vector<vector<int> > >(n+2, vector<vector<int> >(i+2, vector<int>(i)));
    dp[0][0][0] = 1;
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k <= min(i,j); k++) {
        for (int l = 0; l < i; l++) {
          dp[j][k][l] = dp[j-1][k][l];
          if (k > 0) dp[j][k][l] += dp[j-1][k-1][(l-a[j]%i+i)%i];
          dp[j][k][l] %= MOD;
          // if (dp[j][k][l] > 100) cout << j << ' ' << k << ' ' << l << '\n';
        }
      }
    }
    // cout << i << " -> " << dp[n][i][0] << '\n';
    ans += dp[n][i][0];
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}