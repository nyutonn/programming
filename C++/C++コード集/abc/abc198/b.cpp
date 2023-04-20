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
    string n;
    cin >> n;
    reverse(n.begin(),n.end());
    // cout << n << endl;
    rep(i,10){
        bool ok = true;
        rep(j,n.size()){
            if(n[j] != n[n.size()-1-j]){
                ok = false;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
        n += '0';
    }
    cout << "No" << endl;
}
