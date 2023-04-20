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
    ll x, y;
    cin >> x >> y;
    vector<pair<ll, ll>> mp;
    mp.push_back(make_pair(1,1));
    ll gu=0, ki=0;
    while(y != 0){
        if(y%2 == 0) {
            mp.push_back(make_pair(y/2,mp[gu].second + 1));
            gu++;
        }
        else{
            mp.push_back(make_pair(y/2,mp[ki].second + 2));
            mp.push_back(make_pair(y/2+1,mp[ki].second + 2));
            ki += 2;
        }
        y /= 2;
    }
    
}
