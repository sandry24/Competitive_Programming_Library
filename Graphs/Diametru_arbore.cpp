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
vi dist(MAXN);
int maxdist = 0, maxnode = 1;

void dfs(int x, int p){
    for(auto i : adj[x]){
        if(i != p){
            dist[i] = dist[x] + 1;
            if(dist[i] > maxdist){
                maxnode = i;
                maxdist = dist[i];
            }
            dfs(i, x);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dist[1] = 0;
    dfs(1, -1);
    for(int i = 1; i <= n; i++)
        dist[i] = 0;
    maxdist = 0;
    dfs(maxnode, -1);
    cout << maxdist+1 << '\n';
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