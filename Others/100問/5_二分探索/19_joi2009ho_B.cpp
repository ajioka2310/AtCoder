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
  ll d; cin >> d;
  int n,m; cin >> n >> m;
  llvec S(n+1,0); rep(i,n-1) cin >> S[i+1];
  S[n] = d;
  sort(all(S));
  llvec D(m,0); rep(i,m) cin >> D[i];
  
  ll ans = 0;
  rep(i,m){
    decltype(S)::iterator iter_lower = lower_bound(all(S),D[i]);
    int idx_lower = distance(S.begin(),iter_lower);
    if (idx_lower==0){
    }
    else{
      ans += min(S[idx_lower]-D[i],D[i]-S[idx_lower-1]);
    }
  }
  
  cout << ans << endl;
}