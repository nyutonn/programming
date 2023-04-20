#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n, w;
    cin >> n >> w;
    vector<pair<int, pair<int, int>>> p(n);
    rep(i,n){
        cin >> p[i].first >> p[i].second.first >> p[i].second.second;
    }
    sort(p.begin(),p.end());
    ll now = 0;
    ll index = 0;
    rep(i,200005){
        while(1){
            if(index == n){
                cout << "Yes" << endl;
                return 0;
            }
            if(p[index].second.first == )
            if(p[index].first > i) break;
            else {
                now += p[index].second.second;
                index++;
            }
        }
        if(now > w){
            cout << "No" << endl;
            return 0;
        }
        index++;
    }
}
