#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct query{
    int L, R, ind;
    int64_t ord;
 
    inline void calcOrder() {
        ord = gilbertOrder(L, R, 21, 0);
    }
};

inline bool operator<(const query &a, const query &b) {
    return a.ord < b.ord;
}

void Mo_algorithm(vi &a, vector<query> &q, int n, int m){
    vector<ll> ans(m);
    vi freq(1e6+1);
    sort(q.begin(), q.end());
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
        q[i].calcOrder();
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