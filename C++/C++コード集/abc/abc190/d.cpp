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

bool find(vector<string> vec, string number) {
  auto itr = find(vec.begin(), vec.end(), number);
  size_t index = distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
  }
  else { // 発見できなかったとき
    return false;
  }
}

int main(){
    vector<string> v = {"a", "b", "c", "d"};
    if(find(v, "a")) cout << 1 << endl;
}
