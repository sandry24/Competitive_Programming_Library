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

struct edge {
    int a, b, w;
};

vector<edge> e;
vector<ll> dist(50005, 1e18); 

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        edge ed;
        cin >> ed.a >> ed.b >> ed.w;
        e.pb(ed);
    }
    dist[1] = 0;
    for(;;){
        bool any = false;
        for(int i = 0; i < m; i++){
            if(dist[e[i].a] < 1e18){
                if(dist[e[i].b] > dist[e[i].a] + e[i].w){
                    dist[e[i].b] = dist[e[i].a] + e[i].w;
                    any = 1;
                }
            }
        }
        if(!any)
            break;
    }
    //daca in problema pot fi cicluri negative atunci outer for ii pana la n 
    //si dist[e[i].b] va fi minimum -INF pentru nu face overflow
    for(int i = 2; i <= n; i++)
        cout << dist[i] << ' ';
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