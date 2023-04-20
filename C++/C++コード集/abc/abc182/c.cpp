#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#include <iostream>
#include <string>

int main(){
    string n2;
    cin >> n2;
    int zero = 0, one = 0, two = 0;
    int keta = n2.size();
    rep(i,keta){
        ll tmp = n2[i];
        if(tmp%3 == 0) zero++;
        else if(tmp%3 == 1) one++;
        else two++;
    }
    int sum = one * 1 + two * 2;
    int amari = sum%3;
    if(amari == 0) cout << 0 << endl;
    else if(amari%3 == 0) cout << 0 << endl;
    else if(amari%3 == 1 && one >= 1 && keta >= 2) cout << 1 << endl;
    else if(amari%3 == 1 && two >= 2 && keta >= 3) cout << 2 << endl;
    else if(amari%3 == 2 && two >= 1 && keta >= 2) cout << 1 << endl;
    else if(amari%3 == 2 && one >= 2 && keta >= 3) cout << 2 << endl;
    else cout << -1 << endl;    
}
