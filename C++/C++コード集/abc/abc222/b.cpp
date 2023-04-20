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
    int n, p;
    cin >> n >> p;
    int cnt = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a < p) cnt ++;
    }
    cout << cnt << endl;
}
