// abc118 D - Match Matching
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

template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};

const int INF=INT32_MAX/2;
const int MOD=1e9+7;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

bool cmp(pair_int a, pair_int b) { return a.second < b.second; }


string check(string res1, string res2){
  if (res1.size()>res2.size()) return res1;
  else if (res1.size()<res2.size()) return res2;
  else {
    if (res1>res2) return res1;
    else return res2;
  }
}

int main(){
  map<int,int> dict_base;
  dict_base[1] = 2;
  dict_base[2] = 5;
  dict_base[3] = 5;
  dict_base[4] = 4;
  dict_base[5] = 5;
  dict_base[6] = 6;
  dict_base[7] = 3;
  dict_base[8] = 7;
  dict_base[9] = 6;
  int N,M; cin>>N>>M;
  v1i32 A(M,0); rep(i,M) cin>>A[i];
  map<int,int> dict;
  rep(i,M){
    int ok = A[i];
    if (!dict.count(dict_base[ok])) dict[dict_base[ok]] = ok;
    else {
      if (dict[dict_base[ok]]<ok) dict[dict_base[ok]] = ok;
    }
  }

  vector<pair_int> ls;
  for (auto &[key,value]: dict){
    ls.push_back({key,value});
  } 
  sort(rall(ls),cmp);
  dump(ls);

  vector<vector<string>> dp(dict.size()+1,vector<string>(N+1,""));


  rep(i,ls.size()){
    rep(j,N+1){
      if (j == ls[i].first){
        dp[i+1][j] = check(dp[i][j],to_string(ls[i].second));
      }//dp[i+1][j-ls[i].first]!=""
      else if (j>ls[i].first){
        string tmp = dp[i+1][j-ls[i].first];
        if (tmp!="") tmp += to_string(ls[i].second);
        dp[i+1][j] = check(tmp,dp[i][j]);
      }
      else{
        dp[i+1][j] = dp[i][j];  
      }
    }

  }
  dump(dp[1]|cp::front(15)|cp::index());
  dump(dp[1]|cp::back(15)|cp::index());
  dump(dp[2]|cp::front(15)|cp::index());
  dump(dp[2]|cp::back(15)|cp::index());
  dump(dp[3]|cp::front(15)|cp::index());
  dump(dp[3]|cp::back(15)|cp::index());
  dump(dp[4]|cp::front(15)|cp::index());
  dump(dp[4]|cp::back(15)|cp::index());
  cout << dp[ls.size()][N] << endl;

}
