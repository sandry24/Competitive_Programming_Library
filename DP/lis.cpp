#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vi dp(n+1, 1e9), ind(n+1, -1), parent(n+1);
    dp[0] = -1e9;
    for(int i = 0; i < n; i++){
        int j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if(dp[j-1] < a[i] && a[i] < dp[j]){
            ind[j] = i;
            parent[i] = ind[j-1];
            dp[j] = a[i];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(dp[i] != 1e9)
            ans = i;
    vi lis;
    int u = ind[ans];
    while(u != -1){
        lis.pb(a[u]);
        u = parent[u];
    }
    reverse(lis.begin(), lis.end());
    cout << ans << '\n';
    for(auto i : lis)
        cout << i << ' ';
    cout << '\n';
}
 
int main(){
    //freopen("coborare.in", "r", stdin);
    //freopen("coborare.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}