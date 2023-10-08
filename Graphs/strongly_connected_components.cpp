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

int n, m;
vector<bool> visited(1e5+5);
//adj_inv este vectorul de adiacenta al grafului opus
vector<vector<int>> adj(1e5+5), adj_inv(1e5+5);
//ans[i] va contine numarul componentei tare conexe din care face parte
vector<int> ans(1e5+5);
//ordinea procesarii nodurilor in partea a 2a a algoritmului
stack<int> L;
 
void dfs(int x){
    visited[x] = 1;
    for(auto i : adj[x]){
        if(!visited[i])
            dfs(i);
    }
    L.push(x);
}
 
void dfs2(int x, int nr){
    visited[x] = 1;
    //atribuim nodului x numarul componentului tare conex din care face parte
    ans[x] = nr;
    for(auto i : adj_inv[x]){
        if(!visited[i])
            dfs2(i, nr);
    }
}
 
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_inv[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i);
    }
    //resetam vectorul visited
    visited = vector<bool>(1e5+5);
    int nr = 0;
    for(int i = 0; i < n; i++){
        int cur = L.top();
        //daca nodul inca nu a fost vizitat
        if(!visited[cur]){
            //marim numarul de componente tari conexe
            nr++;
            //si atribuim fiecarui nod din aceasta componenta numarul nr
            dfs2(cur, nr);
        }
        L.pop();
    }
    cout << nr << '\n';
    //pentru fiecare nod 1..n scriem numarul componentei din care face parte
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
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