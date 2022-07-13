#include <iostream>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

int n;
vector<int> a;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    cin >> n;
    a = vector<int>(n+2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
  }
  return 0;
}