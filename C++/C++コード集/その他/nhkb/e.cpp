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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int k2 = 0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '.') k2 ++;;
    }
    mint k = k2;
    mint sum = k;
    rep(i,k2) sum *= 2;
    vector<vector<int>> t(h, vector<int>(w, 1));
    rep(i,h)rep(j,w){
        for(int migi = j+1; migi < w; migi++){
            if(s[i][migi] == '.') t[i][j] += 1;
            else break;
        }
        for(int hidari = j-1; hidari >= 0; hidari--){
            if(s[i][hidari] == '.') t[i][j] += 1;
            else break;
        }
        for(int sita = i+1; sita < h; sita++){
            if(s[sita][j] == '.') t[i][j] += 1;
            else break;
        }
        for(int ue = i-1; ue >= 0; ue--){
            if(s[ue][j] == '.') t[i][j] += 1;
            else break;
        }
    }
    mint hikusum = 0;
    rep(i,h)rep(j,w){
        if(s[i][j] == '#') continue;
        mint cnt = 1;
        rep(hiku,k2-t[i][j]) cnt *= 2; 
        hikusum += cnt;
    }
    mint ans = sum - hikusum;
    cout << ans << endl;
}
