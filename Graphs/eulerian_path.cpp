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
vector<vector<int>> adj(100005);
vector<int> in_degree(100005), out_degree(100005);
vector<int> res;
 
void dfs(int x){
    //trecem prin fiecare muchie orientata dinspre x si 
    //o stergem dupa care incepem dfs din nodul adiacent
    while(adj[x].size() != 0){
        int to = adj[x].back();
        adj[x].pop_back();
        dfs(to);
    }
    res.push_back(x);
}
 
void solve(){
    //n - numarul de noduri
    //m - numarul de muchii
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        //adaugam muchia a->b in lista de adiacenta
        adj[a].push_back(b);
        //out_degree arata gradul de iesire al fiecarui nod
        out_degree[a]++;
        //in_degree arata gradul de intrare al fiecarui nod
        in_degree[b]++;
    }
    //cautam primul nod care are muchii orientate dinspre el
    int first = 1;
    while(first <= n && out_degree[first] == 0)
        first++;
    //daca nu exista astfel de noduri, nu exista nici drum/ciclu eulerian
    if(first == n+1){
        cout << -1;
        return;
    }
    //v1 va fi nodul care are gradul de iesire = gradul de intrare + 1, daca exista
    //v2 va fi nodul care are gradul de intrare = gradul de iesire + 1, daca exista
    int v1 = -1, v2 = -1; 
    bool invalid_graph = false;
    for(int i = 1; i <= n; i++){
        if(in_degree[i] != out_degree[i]){
            if(v1 == -1 && out_degree[i] == 1 + in_degree[i])
                v1 = i;
            else if(v2 == -1 && in_degree[i] == 1 + out_degree[i])
                v2 = i;
            else
                invalid_graph = true;
        }
    }
    if(v1 != 1 || v2 != n){
        cout << "IMPOSSIBLE\n";
        return;
    }
    //unim cele 2 noduri speciale daca exista cu o muchie imaginara
    //muchie de la cel cu in_degree mai mare la cel cu out_degree mai mare
    if(v1 != -1)
        adj[v2].push_back(v1);
    dfs(first);
    reverse(res.begin(), res.end());
    if(v1 != -1){
        //scoatem muchia imaginara din ciclu, formand un eulerian path
        for(int i = 0; i < res.size()-1; i++){
            if(res[i] == v2 && res[i+1] == v1) {
                vector<int> res2;
                for(int j = i+1; j < res.size(); j++)
                    res2.push_back(res[j]);
                //incepem de la j = 1 deoarece res[0] == res.back(), fiind un ciclu
                for(int j = 1; j <= i; j++)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }
    //verificam daca au ramas muchii nevizitate
    //in cazul in care au ramas inseamna ca graful nu este conectat
    for(int i = 1; i <= n; i++){
        if(adj[i].size() != 0)
            invalid_graph = true;
    }
    if(invalid_graph)
        cout << "IMPOSSIBLE\n";
    else {
        for(auto i : res)
            cout << i << ' ';
        cout << '\n';
    }
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