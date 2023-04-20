#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll n, m, t;
    cin >> n >> m >> t;
    ll v = n;
    ll TIME = 0;
    rep(i,m){
        ll a, b;
        cin >> a >> b;
        ll mi = a - TIME;
        v -= mi;
        if(v <= 0){
            cout << "No" << endl;
            return 0;
        }
        v = min(n, v + b-a);
        TIME = b;
    }
    v -= (t-TIME);
    if(v > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
