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
    //every move alternatively a player takes either the first or last element from array
    //let dp[l][r] show the highest possible score1 - score2, if we only count the segment l..r
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[i][i] = a[i];
        sum += a[i];
    }
    for(int l = n-1; l >= 0; l--){
        for(int r = l+1; r < n; r++){
            dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    }
    cout << (sum + dp[0][n-1]) / 2 << '\n';
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