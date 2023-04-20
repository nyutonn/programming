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
    cin >> n;
    vector<double> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double disx = x[j] - x[i];
            double disy = y[j] - y[i];
            if(disx == 0) continue;
            double kata = disy / disx;
            if(kata >= -1 && kata <= 1) ans++;
        }
    }
    cout << ans << endl;
}
