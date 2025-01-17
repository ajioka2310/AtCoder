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
  int N;cin>>N;
  vec ls(1000002,0);
  rep(i,N){
    int a,b;cin>>a>>b;
    // cpp_dump(a,b);
    ls[a]++;
    ls[b+1]--;
  }
  // cpp_dump(ls);

  krep(i,1,1000002){
    ls[i] = ls[i-1]+ls[i];
  }
  // cpp_dump(ls);
  int ans = 0;
  rep(i,1000002){
    ans = max(ans,ls[i]);
  }
  cout << ans << endl;


}
