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

int MAXN = 1e5+5;
vector<vi> adj(MAXN);
vector<bool> visited(MAXN);

void dfs(int x){
    visited[x] = 1;
    for(auto i : adj[x]){
        if(!visited[i])
            dfs(i);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << '\n';
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