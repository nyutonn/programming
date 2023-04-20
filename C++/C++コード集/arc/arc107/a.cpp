#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int mod = 998244353;
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 1;
    ans *= (1+c)*c/2;
    ans %= mod;
    ans *= ((1+b)*b/2)%mod;
    ans %= mod;
    ans *= ((1+a)*a/2)%mod;
    ans %= mod;
    cout << ans << endl;
}
