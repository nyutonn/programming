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
    int suma = 0, sumb = 0;
    rep(i,n) {
        int a;
        cin >> a;
        suma += a;
    }
    rep(i,n){
        int b;
        cin >> b;
        sumb += b;
    }
    if(suma > sumb) cout << "A" << endl;
    else if(suma < sumb) cout << "B" << endl;
    else cout << "same" << endl; 
    return 0;
}
