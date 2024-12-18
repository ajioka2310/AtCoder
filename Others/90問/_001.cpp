#ifdef DEFINED_ONLY_IN_LOCAL
#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// <次のセクションの内容はここに追加する>
#define dump(...) cpp_dump(__VA_ARGS__)
namespace cp = cpp_dump;
CPP_DUMP_SET_OPTION_GLOBAL(max_line_width, 80);
CPP_DUMP_SET_OPTION_GLOBAL(log_label_func, cp::log_label::filename());
CPP_DUMP_SET_OPTION_GLOBAL(enable_asterisk, true);
#else
#define dump(...)
#define CPP_DUMP_SET_OPTION(...)
#define CPP_DUMP_SET_OPTION_GLOBAL(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
#endif

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

bool solve(llvec &A, ll check, ll K){
  int cnt = 0;
  int pre = 0;
  krep(i,1,A.size()-1){
    // カットするタイミング
    if (A[i]-pre>=check && A[A.size()-1]-A[i]){
      cnt += 1;
      now = i;
      dump(now);
    }
  }
  dump(K,cnt,check);
  if (cnt>=K) return true;
  else return false;

}

int main(){
  int N,L; cin>>N>>L;
  int K; cin>>K;
  llvec A(N+2,0); rep(i,N) cin>>A[i+1];
  A[N+1] = L;

  ll ng = -1;
  ll ok = L+1;

  while(abs(ok-ng)>1){
    ll check = (ok+ng)/2;
    dump(ok,ng,check,solve(A,check,K));
    if (solve(A,check,K)) ok = check;
    else ng = check;
  }

  cout << right << endl;

  
}
