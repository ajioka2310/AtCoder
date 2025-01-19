// abc122 D - We Like AGC
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

using i64 = long long;
using f80 = long double;
using v1i32 = vector<int>;
using v1i64 = vector<i64>;
using v1str = vector<string>;
using v2i32 = vector<v1i32>;
using v2i64 = vector<v1i64>;
using v3i64 = vector<v2i64>;
using v4i64 = vector<v3i64>;
using v5i64 = vector<v4i64>;

using v2str = vector<v1str>;
using v3i32 = vector<v2i32>;
using v3i64 = vector<v2i64>;
using pair_int = pair<int,int>;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define rrep(i,n) for (int i= int(n)-1; i >=0; --i)
#define reps(i,n) for (int i = 1; i <= int(n); ++i)
#define rreps(i,n) for (int i = int(n); i >= 1; --i)
#define repc(i,n) for (int i = 0; i <= int(n); ++i)
#define rrepc(i,n) for (int i = int(n); i >= 0; --i)

#define krep(i,k,n) for (int i = k; i < (int)(n); ++i)
#define rkrep(i,start,end) for (int i=start-1; i >=end; --i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define each(x,y) for (auto &x:y)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define max_idx(a) max_element(all(a)) - a.begin()
#define min_idx(a) min_element(all(a)) - a.begin()
#define max_value(A) A[max_idx(A)]
#define min_value(A) A[min_idx(A)]
#define sum_values(A) reduce(all(A))

template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};

constexpr i64 INF = (1LL << 60);
const int MOD=1e9+7;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

bool cmp(pair_int a, pair_int b) { return a.second < b.second; }



int main(){
  int N; cin>>N;
  // 0:# 1:A, 2:C, 3:G, 4:T
  v5i64 dp(100+1,v4i64(5,v3i64(5,v2i64(5,v1i64(5,0)))));
  // 1
  krep(i,1,5){
    dp[1][0][0][0][i] = 1;
  }
  // 2
  krep(i,1,5)krep(j,1,5){
    dp[2][0][0][j][i] += dp[1][0][0][0][j];
  }
  // 3
  krep(i,1,5)krep(j,1,5)krep(k,1,5){
    if (
      (k==1&&j==3&&i==2)||
      (k==1&&j==2&&i==3)||
      (k==3&&j==1&&i==2)
    ) continue;
    dp[3][0][k][j][i] += dp[2][0][0][k][j];
  }
  // 4
  krep(i,1,5)krep(j,1,5)krep(k,1,5)krep(l,1,5){
    if (
      (l==1&&k==3&&j==2)||
      (l==1&&k==2&&j==3)||
      (l==3&&k==1&&j==2)
    ) continue;
    if (
      (k==1&&j==3&&i==2)||
      (k==1&&j==2&&i==3)||
      (k==3&&j==1&&i==2)
    ) continue;
    if (
      (l==1&&k==3&&i==2)
    ) continue;
    if (
      (l==1&&j==3&&i==2)
    ) continue;
    if (
      (k==1&&j==3&&i==2)
    ) continue;
    dp[4][l][k][j][i] += dp[3][0][l][k][j];
  }

  krep(n,5,101)krep(i,1,5)krep(j,1,5)krep(k,1,5)krep(l,1,5){
    if (
      (l==1&&k==3&&j==2)||
      (l==1&&k==2&&j==3)||
      (l==3&&k==1&&j==2)
    ) continue;
    if (
      (k==1&&j==3&&i==2)||
      (k==1&&j==2&&i==3)||
      (k==3&&j==1&&i==2)
    ) continue;
    if (
      (l==1&&k==3&&i==2)
    ) continue;
    if (
      (l==1&&j==3&&i==2)
    ) continue;
    if (
      (k==1&&j==3&&i==2)
    ) continue;
    krep(m,1,5){
      dp[n][l][k][j][i] += dp[n-1][m][l][k][j];
      dp[n][l][k][j][i] = dp[n][l][k][j][i]%MOD;
    }
  }




  int res = 0;
  if (N>=4){
    krep(i,1,5)krep(j,1,5)krep(k,1,5)krep(l,1,5){
      res += dp[N][l][k][j][i];
      res = res % MOD;
    }
    cout << res << endl;
  }
  else {
    krep(i,1,5)krep(j,1,5)krep(k,1,5){
      res += dp[N][0][k][j][i];
      res = res % MOD;
    }
    cout << res << endl;
  }
  





}
