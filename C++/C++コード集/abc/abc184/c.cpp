#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vi a2, b2;
    a2 = {1, 2, 2, 1, -1, -2, -2, -1};
    b2 = {2, 1, -1, -2, -2, -1, 1, 2};
    if(a == c && b == d) {
        cout << 0 << endl;
        return 0;
    }
    else if(a+b == c+d || a-b == c-d || abs(a-c) + abs(b-d) <= 3) {
        cout << 1 << endl;
        return 0;
    }
    else if((a+b)%2 == (c+d)%2){
        cout << 2 << endl;
        return 0;
    }
    rep(i,8){
        int a3 = a + a2[i], b3 = b + b2[i];
        if(a3+b3 == c+d || a3-b3 == c-d || abs(a3-c) + abs(b3-d) <= 3){
            cout << 2 << endl;
            return 0;
        }
    }
    
    cout << 3 << endl;
}
