#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main(){
    int t;
    cin >> t;
    rep(i,t){
        int n2, a2, b2;
        cin >> n2 >> a2 >> b2;
        mint n = n2, a = a2, b = b2;
        mint x4, x3, x2, x1, ans;
        
        if(n2-a2-b2 < 0) {
            cout << 0 << endl;
        }
        else{
            x4 = (n-a-b+2)*(n-a-b+1)/2;
            x3 = x4*2;
            x2 = (n-a+1)*(n-b+1);
            x2 -= x3;
            x1 = x2*x2;
            ans = (n-a+1)*(n-a+1)*(n-b+1)*(n-b+1);
            ans -= x1;
            cout << ans << endl;
        }
    }
}
