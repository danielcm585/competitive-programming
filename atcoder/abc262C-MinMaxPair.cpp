#include <iostream>
#include <vector>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

int n;
vector<int> a;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  a = vector<int>(n+2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll ans = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i == a[i]) cnt++;
    else {
      // cout << i << " -> " << (min(a[i],a[a[i]]) == min(i,a[i]) && max(a[i],a[a[i]]) == max(i,a[i])) << '\n';
      ans += min(a[i],a[a[i]]) == min(i,a[i]) && max(a[i],a[a[i]]) == max(i,a[i]);
    }
  }
  ans /= 2;
  ans += cnt*(cnt-1)/2;
  cout << ans << '\n';
  return 0;
}