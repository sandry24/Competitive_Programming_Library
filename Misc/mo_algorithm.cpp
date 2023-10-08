#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
const int block = 450;
 
struct query{
    int L, R, ind;
};
 
bool compare(query x, query y){
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;
    return x.R < y.R;
}
 
void Mo_algorithm(vi &a, vector<query> &q, int n, int m){
    vector<ll> ans(m);
    vi freq(1e6+1);
    sort(q.begin(), q.end(), compare);
    int currL = 0, currR = 0;
    ll currpower = 0;
    for(int i = 0; i < m; i++){
        int L = q[i].L-1, R = q[i].R-1;
        ll temp;
        while(currL < L){
            temp = freq[a[currL]];
            currpower -= temp*temp*a[currL];
            freq[a[currL]]--;
            currpower += (temp-1)*(temp-1)*a[currL];
            currL++;
        }
        while(currL > L){
            temp = freq[a[currL-1]];
            currpower -= temp*temp*a[currL-1];
            freq[a[currL-1]]++;
            currpower += (temp+1)*(temp+1)*a[currL-1];
            currL--;
        }
        while(currR <= R){
            temp = freq[a[currR]];
            currpower -= temp*temp*a[currR];
            freq[a[currR]]++;
            currpower += (temp+1)*(temp+1)*a[currR];
            currR++;
        }
        while(currR > R+1){
            temp = freq[a[currR-1]];
            currpower -= temp*temp*a[currR-1];
            freq[a[currR-1]]--;
            currpower += (temp-1)*(temp-1)*a[currR-1];
            currR--;
        }
        ans[q[i].ind] = currpower;
    }
    for(auto i : ans)
        cout << i << '\n';
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<query> q(m);
    for(int i = 0; i < m; i++){
        cin >> q[i].L >> q[i].R;
        q[i].ind = i;
    }
    Mo_algorithm(a, q, n, m);
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}