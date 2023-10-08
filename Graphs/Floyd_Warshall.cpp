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

ll MAXN = 501, n, m, q;
ll dist[501][501];

void Floyd_Warshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            dist[i][j] = 1e18;
    }
    for(int i = 0; i < m; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w);
    }
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
    Floyd_Warshall();
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << (dist[a][b] == 1e18 ? -1 : dist[a][b]) << '\n';
    }
}  
 
int main(){
    //freopen("bomboane2.in", "r", stdin);
    //freopen("bomboane2.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}