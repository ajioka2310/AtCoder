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
  int H,W; cin>>H>>W;
  Graph ls(10,vec(10));
  rep(i,10){
    rep(j,10){
      int c;cin>>c;
      ls[i][j] = c;
    }
  }
  Graph A(H,vec(W));
  rep(i,H){
    rep(j,W){
      cin >> A[i][j];
    }
  }

  rep(k,10){
    rep(i,10){
      rep(j,10){
        ls[i][j] = min(ls[i][j],ls[i][k]+ls[k][j]);
      }
    }
  }
  int ans = 0;
  rep(i,H){
    rep(j,W){
      if (A[i][j]==-1) continue;
      ans += ls[A[i][j]][1];
    }
  }
  cout << ans << endl;
}
