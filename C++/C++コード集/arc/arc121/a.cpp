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

const ll INF = 1000000000000000;

int main(){
    int n;
    cin >> n;
    vl x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    ll max_x = -INF;
    ll max_y = -INF;
    ll min_x = INF;
    ll min_y = INF;
    rep(i,n){
        max_x = max(max_x, x[i]);
        max_y = max(max_y, y[i]);
        min_x = min(min_x, x[i]);
        min_y = min(min_y, y[i]);
    }
    bool ok_max = true, ok_min = true;
    // cout << ok_min << ok_min << endl;
    rep(i,n){
        if(x[i] == max_x && y[i] == max_y) {
            // cout << "max" << endl;
            ok_max = false;
            // cout << x[i] << max_x << y[i] << max_y << endl;
        }
        if(x[i] == min_x && y[i] == min_y) {
            // cout << "min" << endl;
            ok_min = false;
            // cout << x[i] << min_x << y[i] << min_y << endl;
        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    vl ans(6);
    ans[0] = abs(x[n-1] - x[0]);
    ans[1] = abs(x[n-2] - x[0]);
    ans[2] = abs(x[n-1] - x[1]);
    ans[3] = abs(y[n-1] - y[0]);
    ans[4] = abs(y[n-2] - y[0]);
    ans[5] = abs(y[n-1] - y[1]);
    sort(ans.rbegin(), ans.rend());
    if(ok_max || ok_min) cout << ans[1] << endl;
    else cout << ans[2] << endl;
    // cout << ok_max << ok_min << endl;
}
