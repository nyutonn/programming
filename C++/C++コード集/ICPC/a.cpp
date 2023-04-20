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
        vi a(4);
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) return 0;
        while(1){
            sort(a.begin(), a.end());
            if(a[0] != 0){
                a[1] -= a[0];
                a[2] -= a[0];
                a[3] -= a[0];
            }
            else if(a[1] != 0){
                a[2] -= a[1];
                a[3] -= a[2];
            }
            else if(a[2] != 0){
                a[3] -= a[2];
            }
            else if(a[2] == 0){
                cout << a[3] << endl;
                break;
            }
        }
    }
}
