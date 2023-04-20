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
    ll n;
    cin >> n;
    ll point = 0;
    vl x(n);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        x[i] = 2*a + b;
        point -= a;
    }
    sort(x.rbegin(),x.rend());
    int i = 0;
    while(point <= 0){
        point += x[i];
        i++;
    }
    cout << i << endl;
}
