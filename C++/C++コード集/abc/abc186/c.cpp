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
    int ans = 0;
    for(int i = 1; i<=n; i++){
        int ten = i;
        bool ok = true;
        while(ten != 0){
            if(ten%10 == 7){
                ok = false;
                break;
            }
            ten /= 10;
        }
        int eight = i;
        while(eight != 0){
            if(eight%8 == 7){
                ok = false;
                break;
            }
            eight /= 8;
        }
        if(ok) ans ++;
    }
    cout << ans << endl;
}
