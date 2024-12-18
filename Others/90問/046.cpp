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
  int N; cin>>N;
  vec A(46,0);
  rep(i,N){
    int tmp; cin>>tmp;
    A[tmp%46] +=1;
  }
  vec B(46,0);
  rep(i,N){
    int tmp; cin>>tmp;
    B[tmp%46] +=1;
  }
  vec C(46,0);
  rep(i,N){
    int tmp; cin>>tmp;
    C[tmp%46] +=1;
  }
  dump(A,B,C);

  vector<vector<ll>> dp(3,vector<ll>(46,0));
  // A組み合わせ数
  rep(i,46){
    dp[0][i] = A[i];
  }
  // B組み合わせ数
  rep(i,46){
    rep(j,46){
      dp[1][(i+j)%46] += dp[0][i]*B[j];
    }
  }

  rep(i,46){
    rep(j,46){
      dp[2][(i+j)%46] += dp[1][i]*C[j];
    }
  }

  cout << dp[2][0] << endl;

  
  
}
