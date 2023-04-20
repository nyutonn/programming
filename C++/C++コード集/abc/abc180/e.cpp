#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n;
    cin >> n;
    vi x(n), y(n), z(n);
    rep(i,n) cin >> x[i] >> y[i] >> z[i];
    vvi v (n, vi(n));
    rep(i,n)rep(j,n){
        v[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0, z[i] - z[j]);
    }
    int ans = 0;
    int iti = 0;
    vector<bool> ok(n, true);
    ok[0] = false;
    rep(i,n-1){
        int tasu = 1000000000;
        rep(j,n){
            if(i == j) continue;
            if(!ok[j]) continue;
            tasu = min(tasu, v[i][j]);
        }
        rep(j,n){
            if(tasu == v[i][j]){
                 ok[j] = false;
                 iti = j;
            }
        }
        ans += tasu;
    }
    ans += v[iti][0];
    cout << ans << endl;
}
