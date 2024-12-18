// abc054 D - Mixing Experiment
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
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>
#define Graph vector<vector<int>>
#define llGraph vector<vector<ll>>
#define pair_int pair<int,int>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,start) for (int i=start-1; i >=0; --i)
#define krep(i,k,n) for (int i = k; i < (int)(n); ++i)
#define rkrep(i,start,end) for (int i=start-1; i >=end; --i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define max_idx(a) max_element(all(a)) - a.begin()
#define min_idx(a) min_element(all(a)) - a.begin()
#define max_value(A) A[max_idx(A)]
#define min_value(A) A[min_idx(A)]
#define sum_values(A) accumulate(all(A))


const int INF=INT32_MAX/2;
const int MOD=10007;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}



int main(){
  int N,Ma,Mb; cin>>N>>Ma>>Mb;
  vec A,B,C;
  rep(i,N){
    int a,b,c; cin>>a>>b>>c;
    A.push_back(a);
    B.push_back(b);
    C.push_back(c);
  }
  dump(A,B,C);
  vector<Graph> dp(N+1,Graph(max_value(A)*N+1,vector(max_value(B)*N+1,0)));
  dp[0][0][0] = 0;
  rep(i,N){
    rep(a,max_value(A)*N+1){
      rep(b,max_value(B)*N+1){
        if (A[i]<=a&&B[i]<=b){
          dp[i+1][a][b] = min(dp[i][a-A[i]][b-B[i]]+C[i],dp[i][a][b]);
        }
        else dp[i+1][a][b] = dp[i][a][b];
      }
    }
  }

  int res = INF;
  rep(a,max_value(A)*N+1){
    rep(b,max_value(B)*N+1){
      if (a*Mb==b*Ma&&a*Mb==0){
        res = min(res,dp[N][a][b]);
      }
    }
  }


  cout << res << endl;

}
