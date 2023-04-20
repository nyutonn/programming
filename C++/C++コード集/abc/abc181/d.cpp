#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    string s;
    cin >> s;
    vvi eight(125, vi(10));
    eight[0][0] = 3;
    for(int i = 1; i<=124; i++){
        int hyaku = i*8/100;
        int ten = (i*8-hyaku*100)/10;
        int one = i*8-hyaku*100-ten*10;
        eight[i][hyaku] ++;
        eight[i][ten] ++;
        eight[i][one] ++;
    }
    vi sv(10);
    if(s.size() == 1) sv[0] += 2;
    else if (s.size() == 2) sv[0] ++;
    rep(i,s.size()) {
        int mozi = s[i] - '0';
        sv[mozi] ++;
    }
    if(s.size() <= 2){
        if(s.size() == 1){
            if(stoi(s)%8 == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else{
            if(stoi(s)%8 == 0) cout << "Yes" << endl;
            else{
                reverse(s.begin(),s.end());
                if(stoi(s)%8 == 0) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
        return 0;
    }
    bool ok = false;
    rep(i,125){
        bool tasika = true;
        rep(j,10){
            if(eight[i][j] <= sv[j]) continue;
            else tasika = false;
        }
        if (tasika) ok = true;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
