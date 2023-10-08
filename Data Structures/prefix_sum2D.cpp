#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n+1, vector<ll>(m+1));
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[x][y]++;
    }
    vector<vector<ll>> prefix_sum2D(n+1, vector<ll>(m+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            prefix_sum2D[i][j] = prefix_sum2D[i-1][j] + prefix_sum2D[i][j-1] 
                - prefix_sum2D[i-1][j-1] + (i*j*a[i][j]);
        }
    }
    //sum for rectangle((i1, j1), (i2, j2))
    //cout << prefix_sum2D[i2][j2] - prefix_sum2D[i1-1][j2] - prefix_sum2D[i2][j1-1] + prefix_sum2D[i1-1][j1-1];
}   

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
