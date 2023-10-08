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
 
ll maxn = 501;
vector<vector<ll>> adj(maxn), cap(maxn, vector<ll>(maxn));
vector<bool> visited(maxn);
vector<ll> parent(maxn);
 
ll getmaxflow(ll s, ll d){
    for(ll i = 0; i < maxn; i++)
        visited[i] = parent[i] = 0;
    queue<pair<ll, ll>> q;
    q.push({s, 1e18});
    visited[s] = 1;
    while(!q.empty()){
        ll u = q.front().f;
        ll flow = q.front().s;
        q.pop();
        if(u == d)
            return flow;
        for(auto v : adj[u]){
            if(cap[u][v] == 0 || visited[v])
                continue;
            parent[v] = u;
            visited[v] = 1;
            q.push({v, min(flow, cap[u][v])});
        }
    }
    return 0;
}
 
void solve(){
    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll x, y, c;
        cin >> x >> y >> c;
        adj[x].pb(y);
        adj[y].pb(x);
        cap[x][y] += c;
    }
    ll ans = 0;
    while(ll flow = getmaxflow(1LL, n)){
        ans += flow;
        for(ll u = n; u != 1; u = parent[u]){
            ll v = parent[u];
            cap[v][u] -= flow;
            cap[u][v] += flow;
        }
    }
    cout << ans << '\n';
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