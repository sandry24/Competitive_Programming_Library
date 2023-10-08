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
    //given an array, 0 meaning any number, whats the number of arrays that match
    //any 2 adjacents elements differ by at most 1 absolute unit
    int n, m, mod = 1e9+7;
    cin >> n >> m;
    vi a(n);
    vector<vi> dp(n, vi(m+1));
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(a[0] == 0){
        for(int i = 1; i <= m; i++)
            dp[0][i] = 1;
    } else 
        dp[0][a[0]] = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == 0){
            for(int j = 1; j <= m; j++){
                for(auto k : {j-1, j, j+1}){
                    if(k >= 1 && k <= m){
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= mod;
                    }
                }
            }
        } else {
            for(auto k : { a[i]-1, a[i], a[i]+1}){
                if(k >= 1 && k <= m){
                    dp[i][a[i]] += dp[i-1][k];
                    dp[i][a[i]] %= mod;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans += dp[n-1][i];
        ans %= mod;
    }
    cout << ans << '\n';
}
 
int main(){
    //freopen("rucsac.in", "r", stdin);
    //freopen("rucsac.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}