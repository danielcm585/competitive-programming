#include <iostream>
#include <map>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<ll,ll> pll;

const int N = 1e5+2;
int n;
int ar[N], ans[N];
map<int,int> use;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    memset(ans,-1,sizeof(ans));
    for (int i = 2; i <= n; i++)
    {
        if (ar[i] != ar[i-1])
            ans[i] = ar[i-1];
        use[ans[i]] = 1;
    }
    use[ar[n]] = 1;
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (use[j])
            j++;
        if (ans[i] == -1)
        {
            ans[i] = j;
            use[j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}