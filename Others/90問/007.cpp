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
  int N; cin>>N;
  vec A(N,0); rep(i,N) cin>>A[i];
  sort(all(A));
  int Q; cin>>Q;
  vec B(Q,0); rep(i,Q) cin>>B[i];
  // cpp_dump(A,B);
  
  rep(i,Q){
    int idx_upper = upper_bound(all(A),B[i]) - A.begin();

    if (idx_upper==0) cout << A[idx_upper] - B[i] << endl;
    else{
      cout << min(abs(B[i]-A[idx_upper-1]),abs(B[i]-A[idx_upper])) << endl;
    }
  }
  
}
