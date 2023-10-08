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
    //number of ordered ways you can get sum x with available coins
    int n, x, mod = 1e9+7;
    cin >> n >> x;
    vi a(n), dp(x+1);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - a[i] >= 0){
                dp[j] += dp[j-a[i]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[x] << '\n';
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