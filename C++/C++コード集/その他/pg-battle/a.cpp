#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n, x, a, b;
    cin >>  n >> x >> a >> b;
    if(n >= x) cout << b*n << endl;
    else cout << a*n << endl;
    return 0;
}
