// abc318 C - Blue Spring
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
const int MOD=1e9+7;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

bool cmp(pair_int a, pair_int b) { return a.second < b.second; }


int main(){
  v2i64 memo(3,v1i64(3,0));
  rep(i,3)rep(j,3) cin>>memo[i][j];
  v1i64 memo_flat;
  rep(i,3)rep(j,3) memo_flat.push_back(memo[i][j]);
  v1i64 ls;
  rep(i,10) ls.push_back(i);

  v1i64 check(7,0);
  rep(i,3){
    if (memo[i][0]==memo[i][1]||memo[i][1]==memo[i][2]||memo[i][0]==memo[i][2]){
      check[i]=1;
    }
    if (memo[0][i]==memo[1][i]||memo[1][i]==memo[2][i]||memo[0][i]==memo[2][i]){
      check[i+3]=1;
    }
  }
  if (memo[0][0]==memo[1][1]||memo[0][0]==memo[2][2]||memo[2][2]==memo[1][1]){
    check[6] = 1;
  }
  if (memo[0][2]==memo[1][1]||memo[0][2]==memo[2][0]||memo[2][0]==memo[1][1]){
    check[7] = 1;
  }
  i64 res = 0;
  do{
    bool flg = false;
    map<i64,i64> dict;
    map<i64,i64> dict_inv;
    rep(i,10){
      dict[ls[i]] = i;
      dict_inv[i] = ls[i];

    }

    rep(i,3){
      v1i64 tmp_ls;
      if (check[i]==0) continue;
      rep(j,3) tmp_ls.push_back(dict[i*3+j]);
      sort(all(tmp_ls));
      if (memo_flat[tmp_ls[0]]==memo_flat[tmp_ls[1]]){
        flg = true;
      }
    }
    rep(i,3){
      v1i64 tmp_ls;
      if (check[i+3]==0) continue;
      rep(j,3) tmp_ls.push_back(dict[i+j*3]);
      sort(all(tmp_ls));
      if (memo_flat[tmp_ls[0]]==memo_flat[tmp_ls[1]]){
        flg = true;
      }
    }

    if (check[6]==1){
      v1i64 tmp_ls;
      tmp_ls.push_back(dict[0]);
      tmp_ls.push_back(dict[4]);
      tmp_ls.push_back(dict[8]);
      sort(all(tmp_ls));
      if (memo_flat[tmp_ls[0]]==memo_flat[tmp_ls[1]]){
        flg = true;
      }
    }

    if (check[7]==1){
      v1i64 tmp_ls;
      tmp_ls.push_back(dict[2]);
      tmp_ls.push_back(dict[4]);
      tmp_ls.push_back(dict[6]);
      sort(all(tmp_ls));
      if (memo_flat[tmp_ls[0]]==memo_flat[tmp_ls[1]]){
        flg = true;
      }
    }
    if (flg) res++;
  }
  while(next_permutation(all(ls)));

  double a = (362880-res)/362880;
  std::cout << std::fixed << std::setprecision(10) << a << std::endl;
}

// 362880