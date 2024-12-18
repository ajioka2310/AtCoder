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
const int INF=INT_MAX/2;
const int MOD=10007;

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;

int main(){
  int N; cin>>N;
  vec A(N,0); rep(i,N) cin>>A[i];
  vec ans(N,INF);
      
  rep_auto(i,A){
    int idx_lower = lower_bound(all(ans),i)-ans.begin();
    ans[idx_lower] = i;
  }
  // cpp_dump(ans);
  int res = -1;
  rep(i,N){
    if (ans[i]==INF){
      // cpp_dump(i);
      res = i;break;
    }
  }
  if (res==-1) cout << N << endl;
  else cout << res << endl;
}
