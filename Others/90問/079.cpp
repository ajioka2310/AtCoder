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


int main(){
  int H,W; cin>>H>>W;
  Graph A(H,vec(W,0)); rep(i,H){rep(j,W) cin>>A[i][j];}
  Graph B(H,vec(W,0)); rep(i,H){rep(j,W) cin>>B[i][j];}
  ll ans = 0;
  rep(i,H-1){
    rep(j,W-1){
      int sub = B[i][j] - A[i][j];
      ans += abs(sub);
      B[i][j] -= sub;
      B[i+1][j] -= sub;
      B[i][j+1] -= sub;
      B[i+1][j+1] -= sub;
    }
  }
  dump(A,B);
  ll check = 0;
  rep(i,H){
    rep(j,W){
      check += abs(B[i][j]-A[i][j]);
    }
  }
  if (check==0){
    cout << "Yes" << endl;
    cout << ans << endl;
  }
  else{
    cout << "No" << endl;
  }
}
