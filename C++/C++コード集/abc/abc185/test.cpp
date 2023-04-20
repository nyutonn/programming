#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#include <atcoder/all>
using namespace atcoder;
 
int op(int x, int y) { return x^y; } 
int e() { return 0; }

int main(){
    int n, q;
    cin >> n >> q;
    segtree<int, op, e> t(n);
    rep(i,n){
        int a;
        cin >> a;
        t.set(i,a);
    }
    rep(iq,q){
        int type, x, y;
        cin >> type >> x >> y;
        x--;
        if(type == 1) t.set(x, t.get(x)^y);
        else{
            int ans = t.prod(x,y);
            cout << ans << endl;
        }
    }
}