#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
// #include <atcoder/all>
// using namespace atcoder;

int main(){
    int h, w;
    cin >> h >> w;
    vvi a(h,vi(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    int mn = 1000;
    rep(i,h)rep(j,w){
        mn = min(mn, a[i][j]);
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        ans += (a[i][j] - mn);
    }
    cout << ans << endl;
}
