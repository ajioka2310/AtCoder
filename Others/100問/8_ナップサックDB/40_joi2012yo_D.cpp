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
  int N,K;cin>>N>>K;
  vec ls(N+1,-1);
  rep(i,K){
    int A,B;cin>>A>>B;
    ls[A] = B-1;
  }

  vector<vector<vector<int>>> dp(N+1,Graph(3,vec(3,0)));
  map<int,vec> target{
    {0,{1,2}},
    {1,{0,2}},
    {2,{1,0}}
  };

  // 初日
  if(ls[1]!=-1){
    dp[1][ls[1]][1] = 1;
  }
  else{
    rep(i,3) dp[1][i][1] = 1;
  }

  // cpp_dump(dp);

  int A = 10000;
  krep(i,2,N+1){
    if (ls[i]!=-1){
      // 1
      for (auto l: target[ls[i]]){
        krep(k,1,3){
          dp[i][ls[i]][1] += dp[i-1][l][k];
          dp[i][ls[i]][1] = dp[i][ls[i]][1]%A;
        }
      }
      // 2
      dp[i][ls[i]][2] += dp[i-1][ls[i]][1];
      dp[i][ls[i]][2] = dp[i][ls[i]][2]%A;

    }

    else{
      // 1
      rep(j,3){
        for (auto l: target[j]){
          krep(k,1,3){
            dp[i][j][1] += dp[i-1][l][k];
            dp[i][j][1] = dp[i][j][1]%A;

          }
        }
      }
      // 2
      rep(j,3){
        dp[i][j][2] += dp[i-1][j][1];
        dp[i][j][2] = dp[i][j][2]%A;

      }
    }
    // cpp_dump(i,dp);
  }
  ll ans = 0;
  rep(j,3){
    rep(k,3){
      ans += dp[N][j][k];
      ans = ans%A;
    }
  }
  cout << ans << endl;

}


  


