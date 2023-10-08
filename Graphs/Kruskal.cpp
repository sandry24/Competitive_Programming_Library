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

int MAXN = 200007;
vi parent(MAXN), size(MAXN);
vector<vi> edges;

void make_set(int v){
    size[v] = 1;
    parent[v] = v;
}

int find_parent(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find_parent(parent[v]);
}

void union_set(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a != b){
        if(size[a] < size[b])
            swap(a, b);
        size[a] += size[b];
        parent[b] = a;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb({w, a, b});
    }
    for(int i = 1; i <= n; i++)
        make_set(i);
    sort(edges.begin(), edges.end());
    int mst_weight = 0;
    vector<pi> MST;
    for(auto i : edges){
        int a = i[1], b = i[2], w = i[0];
        if(find_parent(a) != find_parent(b)){
            union_set(a, b);
            mst_weight += w;
            MST.pb({a, b});
        }
    }
    cout << mst_weight << '\n';
    cout << MST.size() << '\n';
    for(auto i : MST)
        cout << i.f << ' ' << i.s << '\n';
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