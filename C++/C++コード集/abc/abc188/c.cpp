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
    int kai = pow(2,n);
    vector<pair<int,int>> a(kai);
    rep(i,kai) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    rep(i,n-1){
        vector<pair<int,int>> b(kai/2);
        for(int j=0; j<kai; j+=2){
            b[j/2].first = max(a[j].first,a[j+1].first);
            if(a[j].first > a[j+1].first) b[j/2].second = a[j].second;
            else b[j/2].second = a[j+1].second;
            // cout << b[j] << endl;
        }
        rep(j, kai/2) {
            a[j].first = b[j].first;
            a[j].second = b[j].second;
        }
        kai /= 2;
        // rep(j,kai) cout << b[j].second << " ";
        // cout << endl;
    }
    if(a[0].first > a[1].first) cout << a[1].second << endl;
    else cout << a[0].second << endl;
}
