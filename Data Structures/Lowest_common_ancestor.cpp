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

int MAXN = 100005;
vector<vi> adj(MAXN);
vi euler, first(MAXN), height(MAXN);

void dfs(int x, int p, int h){
    first[x] = euler.size();
    height[x] = h;
    euler.pb(x);
    for(auto i : adj[x]){
        if(i != p){
            dfs(i, x, h+1);
            euler.pb(x);
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    dfs(1, -1, 1);
    vector<vi> sparse_table(euler.size()+1, vi(25));
    for(int i = 1; i <= euler.size(); i++){
        sparse_table[i][0] = euler[i-1];
    }
    for(int j = 1; j < 25; j++){
        for(int i = 1; i + (1 << j) - 1 <= euler.size(); i++){
            int left = sparse_table[i][j-1];
            int right = sparse_table[i + (1 << (j-1))][j-1];
            sparse_table[i][j] = (height[left] < height[right]) ? left : right;
        }
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a = first[a]+1; b = first[b]+1;
        if(a > b)
            swap(a, b);
        int w = (int)log2(b-a+1);
        int left = sparse_table[a][w];
        int right = sparse_table[b - (1 << w) + 1][w];
        cout << ((height[left] < height[right]) ? left : right) << '\n';
    }
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