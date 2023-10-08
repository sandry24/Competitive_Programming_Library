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

vi parent(200005);
vector<vi> dp(200005, vi(20, -1));
 
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        parent[i] = x;
    }
    for(int i = 1; i <= n; i++)
        dp[i][0] = parent[i];
    for(int h = 1; h < 20; h++){
        for(int i = 1; i <= n; i++){
            if(dp[i][h-1] != -1)
                dp[i][h] = dp[dp[i][h-1]][h-1];
        }
    }
    for(int i = 0; i < q; i++){
        int a, k;
        cin >> a >> k;
        int ans = a, level = k;
        for(int i = 19; i >= 0; i--){
            if(dp[ans][i] != -1 && (1 << i) <= level){
                ans = dp[ans][i];
                level -= (1 << i);
            }
        }
        cout << (ans ? ans : -1) << '\n';
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