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
    double x;
    cin >> n >> x;
    vector<double> v(n), p(n);
    rep(i,n) cin >> v[i] >> p[i];
    double sum = 0;
    for (int i=1; i<=n; i++){
        sum += v[i-1] * p[i-1];
        if(sum > x*100){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
