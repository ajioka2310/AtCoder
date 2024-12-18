#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>

#define graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;

int main(){
  int n; cin >> n;
  vec S(n,0); rep(i,n) cin >> S[i];
  int q; cin >> q;
  vec T(q,0); rep(i,q) cin >> T[i];

  int ans = 0;
  rep(i,q){
    if (binary_search(all(S),T[i])) ans += 1;
  }
  
  cout << ans << endl;
}