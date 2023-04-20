#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    char s, t;
    cin >> s >> t;
    if(s == 'N') cout << t << endl;
    else {
      t = t - 'a' + 'A';
      cout << t << endl;
    }
}
