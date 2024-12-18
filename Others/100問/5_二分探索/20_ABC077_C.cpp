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
  int N; cin >> N;
  llvec A(N,0); rep(i,N) cin >> A[i];
  llvec B(N,0); rep(i,N) cin >> B[i];
  llvec C(N,0); rep(i,N) cin >> C[i];
  sort(all(A));sort(all(B));sort(all(C));
  ll ans = 0;
  rep(i,N){
    // A -> B -> C
    ll idx_lower_a = lower_bound(all(A),B[i]) - A.begin();
    ll idx_upper_c = upper_bound(all(C),B[i]) - C.begin();
    ans += idx_lower_a * (N-idx_upper_c);
  }
  
  cout << ans << endl;
}