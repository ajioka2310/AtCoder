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
#define all(a) (a).begin(), (a).end()


// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"


int main(){
  // input
  int N,M;cin>>N>>M;
  vec dist(N+1,0);krep(i,1,N+1) cin>>dist[i];
  vec wea(M);rep(i,M) cin>>wea[i];
  Graph dp(M,vec(N+1,100100100));
  // 左端処理
  rep(i,M) dp[i][0] = 0;
  // day 1
  dp[0][0] = 0;
  dp[0][1] = wea[0]*dist[1];


  krep(i,1,M){
    krep(j,1,N+1){
      dp[i][j] = min(
        dp[i-1][j-1]+wea[i]*dist[j],
        dp[i-1][j]
      );
    }
  }
  // cpp_dump(dp | cpp_dump::back(20) | cpp_dump::back(5) | cpp_dump::dec(2));
  int res = 1001001001;
  rep(i,M) res = min(res,dp[i][N]);
  cout << res << endl;
}


  



