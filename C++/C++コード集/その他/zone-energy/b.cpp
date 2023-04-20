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
    int n;
    double D, H;
    cin >> n >> D >> H;
    double highwari = 10000000;
    double high = 0;
    vector<double> d(n), h(n);
    rep(i,n) cin >> d[i] >> h[i];
    rep(i,n){
        double wari = (H-h[i])/(D-d[i]);
        // cout << h[i] - d[i]*wari << " "  << wari << endl;
        if(highwari > wari && h[i] - d[i]*wari > 0){
            highwari = min(wari, highwari);
            high = h[i] - d[i] * wari;
        }
    }
    cout << high << endl;
    // if(high > 0) cout << high << endl;
    // else cout << 0 << endl;
}
