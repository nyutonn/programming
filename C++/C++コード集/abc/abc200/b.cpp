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
    ll n, k;
    cin >> n >> k;
    rep(i,k){
        if(n%200 == 0) n /= 200;
        else n = n*1000 + 200;
    }
    cout << n << endl;
}
