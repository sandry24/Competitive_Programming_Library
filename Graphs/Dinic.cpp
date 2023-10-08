#include <bits/stdc++.h>
//#include "grader.h"
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

struct FlowEdge{
    int v, u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vi> adj;
    int n, m = 0;
    int s, t;
    vi ptr, level;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n+1);
    }

    void add_edge(int v, int u, ll cap){
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].pb(m);
        adj[u].pb(m+1);
        m += 2;
    }

    bool bfs(){
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto id : adj[v]){
                if(edges[id].cap - edges[id].flow < 1)
                    continue;
                if(level[edges[id].u] != 0)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != 0;
    }

    ll dfs(int v, ll pushed){
        if(pushed == 0)
            return 0;
        if(v == t)
            return pushed;
        for(int& cid = ptr[v]; cid < adj[v].size(); cid++){
            int id = adj[v][cid];
            int u = edges[id].u;
            if(level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if(tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll max_flow(){
        ll f = 0;
        while(true){
            level = ptr = vi(n+1);
            level[s] = 1;
            q.push(s);
            if(!bfs())
                break;
            while(ll pushed = dfs(s, flow_inf))
                f += pushed;
        }
        return f;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    Dinic graph(n, 1, n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.add_edge(a, b, c);
    }
    cout << graph.max_flow() << '\n';
}

int main(){
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    ///cin >> t;
    while(t--){
        solve();
    }
}