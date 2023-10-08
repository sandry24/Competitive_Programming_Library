#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<vi> BIT(1005, vi(1005));

//one-indexing
void add(int x, int y, int delta){
    for(int i = x; i < 1005; i += i & -i){
        for(int j = y; j < 1005; j += j & -j)
            BIT[i][j] += delta;
    }
}

int sum(int x, int y){
    int sum = 0;
    for(int i = x; i > 0; i -= i & -i)
        for(int j = y; j > 0; j -= j & -j)
            sum += BIT[i][j];
    return sum;
}

/* zero-indexing
int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += BIT[i][j];
    return ret;
}

void add(int x, int y, int delta) {
    for (int i = x; i < 1005; i = i | (i + 1))
        for (int j = y; j < 1005; j = j | (j + 1))
            BIT[i][j] += delta;
}*/
 
void solve(){
    int q;
    cin >> q;
    for(int i = 0; i < 1005; i++){
        for(int j = 0; j < 1005; j++)
            BIT[i][j] = 0;
    }
    for(int i = 0; i < q; i++){
        int type, h, w;
        cin >> type >> h >> w;
        if(type == 1)
            add(h, w, 1);
        else
            cout << sum(h-1, w-1) << '\n';
    }
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
