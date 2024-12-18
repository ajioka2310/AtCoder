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
  int N;cin>>N;
  vec ls(N,0); rep(i,N) cin>>ls[i];

  vector<llvec> dp(N-1,llvec(21,0));

  dp[0][ls[0]] = 1;

  krep(i,1,N-1){
    int num = ls[i];
    rep(j,21){
      if (j+num<=20) {

        dp[i][j] += dp[i-1][j+num];
      }
      if (j-num>=0)
      {
        dp[i][j] += dp[i-1][j-num];

      }
    }
  }
  cout << dp[N-2][ls[N-1]] << endl;

}


  


