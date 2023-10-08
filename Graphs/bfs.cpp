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
vector<ll> dist(MAXN, 1e18), parent(MAXN);

void bfs(int x){
    queue<int> q;
    dist[x] = 0;
    parent[x] = -1;
    visited[x] = 1;
    q.push(x);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : adj[v]){
            if(!visited[u]){
                visited[u] = 1;
                dist[u] = dist[v] + 1;
                parent[u] = v;
                q.push(u);
            }
        }
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
    bfs(1);
    if(dist[n] == 1e18){
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << dist[n]+1 << '\n';
    int u = n;
    vi path;
    while(u != -1){
        path.pb(u);
        u = parent[u];
    }
    reverse(path.begin(), path.end());
    for(auto i : path)
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