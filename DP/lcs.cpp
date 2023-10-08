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

void solve(){
    string s, t;
    cin >> s >> t;
    vector<vi> lcs_table(s.size()+1, vi(t.size()+1));
    for(int i = 0; i <= s.size(); i++){
        for(int j = 0; j <= t.size(); j++){
            if(i == 0 || j == 0)
                lcs_table[i][j] = 0;
            else if(s[i-1] == t[j-1])
                lcs_table[i][j] = lcs_table[i-1][j-1] + 1;
            else 
                lcs_table[i][j] = max(lcs_table[i-1][j], lcs_table[i][j-1]);
        }
    }
    string lcs = "";
    int i = s.size(), j = t.size();
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            lcs += s[i-1];
            i--;
            j--;
        } else if(lcs_table[i-1][j] > lcs_table[i][j-1])
            i--;
        else
            j--;
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs.size() << '\n' << lcs << '\n';
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