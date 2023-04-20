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
    int v, t, s, d;
    cin >> v >> t >> s >> d;
    if(v*t <= d && d <= v*s) cout << "No" << endl;
    else cout << "Yes" << endl;
}
