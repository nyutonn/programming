#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n;
    cin >> n;
    vi a(2*n);
    rep(i,2*n) cin >> a[i];
    vi ans(2*n-1);
    vector<pair<int, int>> p(n);
    rep(i,2*n){
        if(p[a[i]].first == 1) {
            ans[i - p[a[i]].second - 1] ++;
        }
        else{
            p[a[i]].first = 1;
            p[a[i]].second = i;
        }
    }
    int kotae = 0;
    rep(i,2*n-1){
        kotae += ans[i];
        cout << kotae << endl;
    }
    return 0;
}
