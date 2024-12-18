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
  int N,W;cin>>N>>W;
  vector<pair_int> ls(N);
  rep(i,N){
    int v,w;cin>>v>>w;
    ls[i] = {v,w};
  }

  Graph dp(N+1,vec(W+1,0));
  krep(i,1,N+1){
    int v = ls[i-1].first;
    int w = ls[i-1].second;
    krep(j,1,W+1){
      // cpp_dump(i,j);
      // cpp_dump(dp);

      if (j-w>=0){
        dp[i][j] = max(dp[i-1][j-w]+v,dp[i-1][j]);
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  cout << dp[N][W] << endl;
  

}


  


