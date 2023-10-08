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
vi color(MAXN), parent(MAXN);
int cycle_start = -1, cycle_end = -1;

bool dfs(int x){
    color[x] = 1;
    for(auto i : adj[x]){
        if(color[i] == 0){
            parent[i] = x;
            if(dfs(i));
                return true;
        } else if(color[i] == 1){
            cycle_start = i;
            cycle_end = x;
            return true;
        }
    }
    color[x] = 2;
    return false;
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
        if(color[i] == 0 && dfs(i))
            break;
    }
    if(cycle_start == -1){
        cout << "No cycle\n";
        return;
    }
    vi cycle;
    int u = cycle_end;
    while(u != cycle_start){
        cycle.pb(u);
        u = parent[u];
    }
    cycle.pb(u);
    cycle.pb(cycle_end);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << '\n';
    for(auto i : cycle)
        cout << i << ' ';
    cout << '\n';
}  
 
int main(){
    //freopen("coborare.in", "r", stdin);
    //freopen("coborare.out", "w", stdout);
    //ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}