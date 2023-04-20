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
        vi d(n);
        rep(i,n) cin >> d[i];
        int cnt = 0;
        rep(i,n-3){
            if(d[i] == 2 && d[i+1] == 0 && d[i+2] == 2 && d[i+3] == 0){
                cnt ++;
            }
        }
        cout << cnt << endl;
    }
}
