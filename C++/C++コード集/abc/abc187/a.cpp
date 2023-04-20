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
    int a, b;
    cin >> a >> b;
    int ans1 = 0, ans2 = 0;
    while(a != 0){
        ans1 += a%10;
        a /= 10;
    }
    while(b != 0){
        ans2 += b%10;
        b/= 10;
    }
    int ans = max(ans1, ans2);
    cout << ans << endl;
}
