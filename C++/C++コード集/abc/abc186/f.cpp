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

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int main(){
    int t;
    cin >> t;
    rep(i,t){
        ll n, s, k;
        cin >> n >> s >> k;
        ll g = gcd(s, gcd(n, k));
        ll s2 = s/g, k2 = k/g, n2 = n/g;
        ll m =  (s2 * modinv(k2,n2)) % n2;
        if(gcd(k2,n2) == 1) cout << n2 - m << endl;
        else cout << -1 << endl;
    }
}
