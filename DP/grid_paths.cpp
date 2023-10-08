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
    //nxn grid, some cells have traps, how many ways to go from (1, 1) to (n, n)
    int n, mod = 1e9+7;
    cin >> n;
    vector<vector<char>> grid(n+1, vector<char>(n+1));
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> grid[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] == '*')
                continue;
            if(i == 1 && j == 1)
                dp[i][j] = 1;
            if(grid[i-1][j] != '*')
                dp[i][j] += dp[i-1][j];
            if(grid[i][j-1] != '*')
                dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][n] << '\n';
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