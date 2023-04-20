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
    vl a(n);
    rep(i,n) cin >> a[i];
    ll now = 0;
    ll ans = 0;
    ll sum = 0;
    ll mxsum = 0;
    rep(i,n){
        ans = max(ans, now + mxsum);
        mxsum = max(mxsum, sum + a[i]);
        sum += a[i];
        now += sum;
        ans = max(ans, now);
        // cout << mxsum << endl;
    }
    cout << ans << endl;
}
