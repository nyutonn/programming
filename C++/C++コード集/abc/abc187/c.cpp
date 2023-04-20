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
    int n;
    cin >> n;
    vector<string> fir, sec;
    rep(i,n){
        string s;
        cin >> s;
        if(s[0] != '!') fir.push_back(s);
        else {
            reverse(s.begin(),s.end());
            s.pop_back();
            reverse(s.begin(),s.end());
            sec.push_back(s);
        }
    }
    sort(fir.begin(),fir.end());
    sort(sec.begin(),sec.end());

    rep(i,fir.size()){
        int left = -1, right = sec.size();
        while(right - left > 1){
            int mid = (right + left) / 2;
            if(sec[mid] == fir[i]){
                cout << sec[mid] << endl;
                return 0;
            }
            else if(sec[mid] > fir[i]) right = mid;  
            else left = mid;
        }

    }
    cout << "satisfiable" << endl;
}
