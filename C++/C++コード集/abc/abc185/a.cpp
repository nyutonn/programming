#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = min(a, min(b,min(c,d)));
    cout << ans << endl;
}
