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
    //given a rectangle, what is the minimum number to cut it into squares such that every side remains an integer
    int a, b;
    cin >> a >> b;
    vector<vi> dp(a+1, vi(b+1, 1e9));
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int k = 1; k <= i/2; k++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            for(int k = 1; k <= j/2; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        }
    }
    cout << dp[a][b] << '\n';
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