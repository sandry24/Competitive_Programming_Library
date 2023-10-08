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
vi parent(2005);
vi key(2005, 2e9);
vector<bool> in_MST(2005);
vector<vi> adj(2005, vi(2005, 2e9));
//theres no need for adjacency matrix if you dont need mst weight
//or you can use a map to store the weights so you can easily access them at the end

void Prim(){
    key[1] = 0;
    parent[1] = -1;
    for(int i = 0; i < n-1; i++){
        //find the minimum key node from all unvisited
        int mine = 2e9, v = -1;
        for(int j = 1; j <= n; j++){
            if(key[j] < mine && !in_MST[j]){
                mine = key[j];
                v = j;
            }
        }
        //put the node in the MST and update all adjacent node keys
        in_MST[v] = 1;
        for(int u = 1; u <= n; u++){
            if(adj[v][u] != 2e9 && adj[v][u] < key[u] && !in_MST[u]){
                parent[u] = v;
                key[u] = adj[v][u];
            }
        }
    }
}
 
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = min(adj[a][b], w);
        adj[b][a] = min(adj[b][a], w);
    }
    Prim();
    int mst_weight = 0;
    for(int i = 2; i <= n; i++){
        mst_weight += adj[i][parent[i]];
        cout << i << ' ' << parent[i] << '\n';
    }
    cout << mst_weight << '\n';
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