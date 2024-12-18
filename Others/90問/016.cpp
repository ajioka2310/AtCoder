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

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}


// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;


int main(){
  ll N; cin>>N;
  vector<ll> A(3,0); rep(i,3) cin>>A[i];

  ll ans = INF;
  // cpp_dump(N,A);
  rep(i,10000){
    rep(j,10000){
      ll now = N - A[1]*i - A[2]*j;
      if(now>=0 && now%A[0]==0 && now/A[0]>=0){
        ans = min(ans,i+j+now/A[0]);
      }
    }
  }
  cout << ans << endl;
}
