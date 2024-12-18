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
  rep(i,N){
    string s1,s2;cin>>s1>>s2;
    vector<char> ls1(s1.begin(),s1.end());
    vector<char> ls2(s2.begin(),s2.end());
    // cpp_dump(ls1,ls2);
    // vector<vector<int>> dp(ls2.size(),vector<int>(ls1.size(),0));
    int dp[ls2.size()][ls1.size()];
    rep(i,ls2.size()){
      if (ls2[i]==ls1[0]) dp[i][0] = 1;
      else {
        if (i==0) dp[0][0] = 0;
        else dp[i][0] = dp[i-1][0];
      }
    }
    rep(i,ls1.size()){
      if (ls2[0]==ls1[i]) dp[0][i] = 1;
      else {
        if (i==0) dp[0][0] = 0;
        else dp[0][i] = dp[0][i-1];
      }
    }

    // cpp_dump(dp);
    krep(i,1,ls2.size()){
      krep(j,1,ls1.size()){
        // cpp_dump(i,j);
        if (ls2[i]==ls1[j]){
          dp[i][j] = max(max(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]+1);
        }
        else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
      }
    }

    // cpp_dump(dp);
    int a = ls2.size()-1;
    int b = ls1.size()-1;
    cout << dp[a][b] << endl;
  }



}


  


