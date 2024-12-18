#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>
#define Graph vector<vector<int>>
#define pair_int pair<int,int>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
const int INF=INT32_MAX/2;
const int MOD=10007;

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;

int main(){
  int N; cin>>N;
  llvec A(N,0); rep(i,N) cin>>A[i];
  llvec B(N+1,0);
  B[1] = A[0];
  krep(i,1,N){
    B[i+1] = A[i]+B[i];
  }
  // cpp_dump(B);

  krep(i,1,N+1){
    ll ans = -1;
    krep(j,0,N-i+1){
      ans = max(ans,B[j+i]-B[j]);
    }
    cout << ans << endl;
  }
}
