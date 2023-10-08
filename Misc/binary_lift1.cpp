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

int k, n, m, o;
int ans[5][5], temp[5][5], dp[50000][17][5][5];
 
void combine(int t[5][5], int a[5][5], int b[5][5]){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            for(int l = 0; l < k; l++){
                t[i][j] = min(t[i][j], a[i][l] + b[l][j]);
            }
        }
    }
}
 
void solve(){
    cin >> k >> n >> m >> o;
    int INF = 1e9+7;
    memset(dp, 0x3f, sizeof dp);
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        dp[a/k][0][a % k][b % k] = w;
    }
    //dp[i][y][j][l] cel mai scurt drum de la k*i + j de la k*(i + 2^y - 1) + l;
    //dp[i][y][j][l] = dp[i][y-1][j][temp] + dp[i + 2^(y-1)[y-1][temp][l];
    for(int y = 1; y < 17; y++){
        for(int i = 0; i + (1 << y) < (n + k - 1) / k; i++){
            combine(dp[i][y], dp[i][y-1], dp[i + (1 << (y-1))][y-1]);
        }
    }
    for(int u = 0; u < o; u++){
        int a, b;
        cin >> a >> b;
        memset(ans, 0x3f, sizeof ans);
        for (int i = 0; i < 5; i++) 
            ans[i][i] = 0;
        ll ord1 = a/k, ord2 = b/k, mod1 = a % k, mod2 = b % k;
        for (int i = 16; i >= 0; i--) {
            if (ord1 + (1 << i) <= ord2) {
                memset(temp, 0x3f, sizeof temp);
                combine(temp, ans, dp[ord1][i]);
                memcpy(ans, temp, sizeof ans);
                ord1 += (1 << i);
            }
        }
        if(ans[mod1][mod2] == 0x3f3f3f3f)
            cout << -1 << '\n';
        else
            cout << ans[mod1][mod2] << '\n';
    }
}    

int main(){
    //freopen("infasuratoare.in", "r", stdin);
    //freopen("infasuratoare.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}