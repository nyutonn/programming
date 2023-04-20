#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n;
    cin >> n;
    vi p(n);
    rep(i,n) {
      cin >> p[i];
    }
    vector<bool> ok(200005, true);
    int min1 = 0;
    rep(i,n){
      ok[p[i]] = false;
      while(1){
        if(ok[min1] == true) break;
        else min1 ++;
      }
      cout << min1 << endl;
    }
}
