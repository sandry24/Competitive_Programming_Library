#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
vector<pi> ans;

void SolveHanoi(int n, int start, int end){
    if(n == 1){
        ans.pb(mp(start, end));
    } else {
        int other = 6 - (start + end);
        SolveHanoi(n-1, start, other);
        ans.pb(mp(start, end));
        SolveHanoi(n-1, other, end);
    }
}

void solve(){
    int n;
    cin >> n;
    SolveHanoi(n, 1, 3);
    cout << ans.size() << '\n';
    for(auto i : ans)
        cout << i.f << ' ' << i.s << '\n';
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
