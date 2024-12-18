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
const int MOD=1e9+7;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}


int main(){
  int N,Q; cin>>N>>Q;
  vec A(N,0); rep(i,N) cin>>A[i];
  vec diff_abs(N+1,0);
  vec diff(N+1,0);
  rep(i,N-1){
    diff_abs[i+2] = abs(A[i+1] - A[i]);
    diff[i+2] = A[i+1] - A[i];
  }
  ll now = 0;
  rep(i,N+1){
    now += diff_abs[i];
  }

  dump(diff,diff_abs);

  rep(i,Q){
    int L,R,V; cin>>L>>R>>V;
    if (L>1){
      diff[L] += V;
      now += abs(diff[L]) - diff_abs[L];
      diff_abs[L] = diff[L];
    }
    if (R<N){
      diff[R+1] -= V;
      now += abs(diff[R+1]) - diff_abs[R+1];
      diff_abs[R+1] = diff[R+1];
    }
    cout << now << endl;
    // dump(L,R,V);
    // dump(diff,diff_abs,now);
  }
}
