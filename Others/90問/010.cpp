#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>
#define Graph vector<vector<int>>
#define llGraph vector<vector<ll>>
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
  Graph score(N,vec(2,0)); rep(i,N){rep(j,2) cin>>score[i][j];}
  int Q; cin>>Q;
  Graph q(Q,vec(2,0)); rep(i,Q){rep(j,2) cin>>q[i][j];}
  
  vec score_sum1(N+1,0),score_sum2(N+1,0);

  krep(i,1,N+1){
    int c = score[i-1][0];
    int p = score[i-1][1];
    if(c==1){
      score_sum1[i] = score_sum1[i-1] + p;
      score_sum2[i] = score_sum2[i-1];
    }
    else{
      score_sum1[i] = score_sum1[i-1];
      score_sum2[i] = score_sum2[i-1] + p;
    }
  }

  rep(i,Q){
    int l = q[i][0];
    int r = q[i][1];
    cout << score_sum1[r]-score_sum1[l-1] << " ";
    cout << score_sum2[r]-score_sum2[l-1] << " ";
    cout << endl;
  }

}
