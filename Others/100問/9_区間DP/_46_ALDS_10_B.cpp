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


#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
namespace cp = cpp_dump;


int main(){
  // input
  int N;cin>>N;
  vec ls(N+1,0);
  cin>>ls[0]>>ls[1];
  krep(i,2,N+1){
    int a;cin>>a>>ls[i];
  }

  
  Graph dp(N+1,vec(N+1,0));
  // 2の時
  krep(i,1,N){
    dp[2][i] = ls[i-1]*ls[i]*ls[i+1];
  }

  krep(i,3,N+1){ //N+1
    krep(j,1,N+2-i){
      cpp_dump(i,j);
      dp[i][j] = min(
        dp[i-1][j]+ls[j-1]*ls[j+i-2]*ls[j+i-1],
        dp[i-1][j+1]+ls[j-1]*ls[j]*ls[j+i-1]
      );
    }
  }
  cpp_dump(ls | cp::dec(2) | cp::index());
  cpp_dump(dp | cp::dec(2) | cp::index());

}


  



