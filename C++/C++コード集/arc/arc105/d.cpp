#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int t;
    cin >> t;
    rep(i,t){
        int n;
        cin >> n;
        vi a(n);
        int gu = 0, ki = 0;
        rep(i,n) {
            cin >> a[i];
            if(a[i]%2 == 0) gu++;
            else ki++;
        }
        if(n==1){
            cout << "Second" << endl;
            continue;
        }
        gu += ki/2;
        int win;
        if(n%2 == 0) win = -1;
        else win = 1;
        if(gu%2 == 1) win *= -1;
        if(win == 1) cout << "First" << endl;
        else cout << "Second" << endl;
    }
}
