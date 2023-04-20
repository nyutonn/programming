#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll n;
    cin >> n;
    vl x(n);
    rep(i,n) cin >> x[i];
    ll m = 0;
    double y = 0;
    ll t = -10000000;
    rep(i,n) m += abs(x[i]);
    rep(i,n) y += x[i]*x[i];
    y = pow(y, 0.5);
    rep(i,n) t = max(t, abs(x[i]));
    cout << m << endl;
    cout << fixed << setprecision(10);
    cout << y << endl;
    cout << t << endl;
}
