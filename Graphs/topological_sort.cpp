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
vi topological;

bool dfs(int x){
    visited[x] = 1;
    for(auto i : adj[x]){
        if(!visited[i])
            dfs(i);
    }
    topological.pb(x);
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i);
    }
    reverse(topological.begin(), topological.end());
    for(auto i : topological)
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