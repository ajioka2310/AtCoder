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
  int D,N;cin>>D>>N;
  vec temp(D,0);rep(i,D) cin>>temp[i];
  Graph wear(N,vec(3,0)); rep(i,N) cin>>wear[i][0]>>wear[i][1]>>wear[i][2];
  vector<vector<pair<int,bool>>> dp(D,vector<pair<int,bool>>(N));

  // cpp_dump(dp[0]);
  // init 
  rep(i,N){
    int todays_temp = temp[0];
    int max_temp = wear[i][1];
    int min_temp = wear[i][0];
    if(min_temp<=todays_temp&&todays_temp<=max_temp) dp[0][i] = {0,true};
  }

  krep(i,1,D){
    int todays_temp = temp[i];

    rep(j,N){
      int max_temp = wear[j][1];
      int min_temp = wear[j][0];
      int C = wear[j][2];
      if(min_temp<=todays_temp&&todays_temp<=max_temp){
        int max_value=0;
        rep(k,N){
          if (dp[i-1][k].second) max_value = max(max_value,abs(C-wear[k][2])+dp[i-1][k].first);
        }
        dp[i][j] = {max_value,true};
      }
      else {
        dp[i][j] = {0,false};
      }
    }
  }
  // cpp_dump(dp);
  int ans=0;
  rep(i,N){
    ans = max(ans,dp[D-1][i].first);
  }
  cout << ans << endl;
}


  



