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
    while(1){
        int n;
        cin >> n;
        if(n == 0) return 0;
        vi a(n);
        rep(i,n) cin >> a[i];
        int cnt = 0;
        while(1){
            sort(a.rbegin(), a.rend());
            if(a[2] == 0) break;
            cnt += a[2];
            a[0] -= a[2];
            a[1] -= a[2];
            a[2] = 0;
        }
        cout << cnt << endl;
    }
}
