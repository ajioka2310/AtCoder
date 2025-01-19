// abc362 E - Count Arithmetic Subsequences
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
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};

constexpr i64 INF = (1LL << 60);
const int MOD=998244353;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

bool cmp(pair_int a, pair_int b) { return a.second < b.second; }


int main(){
  i64 N; cin>>N;
  v1i64 A(N,0); rep(i,N) cin>>A[i];
  map<i64,i64> dict,dict_inv;
  i64 cnt = 1;
  rep(i,N){
    if (dict.contains(A[i])) continue;
    dict[A[i]] = cnt;
    cnt++;
  }
  for (auto &[key,value]: dict){
    dict_inv[value] = key;
  }
  dump(A);
  dump(dict);
  dump(dict_inv);
  // i64 dict_size = dict.size();

  vector<v3i64> dp(N,v3i64(N,v2i64(dict.size()+1,v1i64(dict.size()+1,0))));
  dp[0][0][dict[A[0]]][0] = 1;

  krep(i,1,N){
    rep(k,i+1){
      i64 key_value = dict[A[i]];
      for (auto &[key1,value1]: dict){
        if (k==0){
          if (key_value==value1) dp[i][k][value1][0] = (dp[i-1][k][value1][0]+1)%MOD; 
          else dp[i][k][value1][0] = dp[i-1][k][value1][0]; 
          continue;
        }
        for (auto &[key2,value2]: dict){
          if (k==1){
            if (key_value==value1) dp[i][k][value1][value2] = (dp[i-1][k][value1][value2]+dp[i-1][k-1][value2][0])%MOD;
            else dp[i][k][value1][value2] = dp[i-1][k][value1][value2];
          }
          else{
            // if (i==2){
            //   dump(A[i],value1,value2);
            //   dump(A[i]-dict_inv[value1]==dict_inv[value1]-dict_inv[value2]);
            //   dump(dp[i-1][k][value1][value2]);
            //   dump(dp[i-1][k-1][value1][value2]);
            // }
            if (A[i]-dict_inv[value1]==dict_inv[value1]-dict_inv[value2]){
              dp[i][k][dict[A[i]]][value1] += (dp[i-1][k-1][value1][value2]);
              dp[i][k][dict[A[i]]][value1] = dp[i][k][dict[A[i]]][value1]%MOD;
              dp[i][k][value1][value2] += dp[i-1][k][value1][value2];
              dp[i][k][value1][value2] = dp[i][k][value1][value2]%MOD;
              // dump(dp[i][k][dict[A[i]]][value1]);
            }
            else{
              dp[i][k][value1][value2] += dp[i-1][k][value1][value2];
              dp[i][k][value1][value2] = dp[i][k][value1][value2]%MOD;
            }
          }
        }
      }
    }
  }
  dump(dict);
  dump(dict.size());
  rep(k,N){
    i64 res = 0;
    rep(i,dict.size()+1)rep(j,dict.size()+1){
      res += dp[N-1][k][i][j];
      res = res %MOD;
    }
    cout << res << " ";
  }
  // dump(dp[1]);

  // dump(dp[2]);

  // dump(dp[3]);

  // dump(dp[4]);
  
  // 24 276 106 37 7 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

}
