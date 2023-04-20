#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll n;
    cin >> n;
    ll a = 1;
    for(ll i = 2; i <= n; i++){
        a = lcm(a,i);
    }
    cout << a+1 << endl;
}
