#include <bits/stdc++.h>
using namespace std;
     
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n, m;
vector<vi> adj(200005);
vector<bool> visited(200005);
vector<pi> bridges;
vi tin(200005), low(200005);
int timer = 0;

void dfs(int v, int p = -1){
    visited[v] = 1;
    tin[v] = low[v] = timer++;
    for(auto to : adj[v]){
        if(to == p)
            continue;
        if(visited[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v])
                bridges.pb(mp(v, to));
        }
    }
}

void find_bridges(){
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i);
    }
    bridges.erase(unique(bridges.begin(), bridges.end()), bridges.end());
    for(auto i : bridges)
        cout << i.f << ' ' << i.s << '\n';
}
     
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    find_bridges();
}
    
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}