#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int a, b;
    cin >> a >> b;
    int mx = 2*a+100;
    int ans = mx - b;
    cout << ans << endl;
}
