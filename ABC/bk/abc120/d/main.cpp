// abc120 D - Decayed Bridges
// abc126 E - 1 or 2
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
#define rrep(i,start) for (int i=start; i > 0; --i)
#define krep(i,k,n) for (int i = k; i < (int)(n); ++i)
#define krep_r(i,start,end) for (int i=start; i > end; --i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define max_idx(a) max_element(all(a)) - a.begin()
#define min_idx(a) min_element(all(a)) - a.begin()
#define max_value(A) A[max_idx(A)]
#define min_value(A) A[min_idx(A)]


const int INF=INT32_MAX/2;
const int MOD=10007;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

int main(){
  ll N,M; cin>>N>>M;
  dsu d(N);
  vector<pair<int,int>> breaking(M);
  rep(i,M){
    int a,b; cin>>a>>b;
    --a;--b;
    breaking[i] = {a,b};
  }
  // ｋ個目の橋を落とした時の不便さ
  llvec ans(M,0);
  ans[M-1] = 1LL * N*(N-1)/2;

  krep_r(i,M-1,0){
    dump(i);
    int a = breaking[i].first;
    int b = breaking[i].second;
    if (d.same(a,b)) ans[i-1] = ans[i];
    else{
      ans[i-1] = ans[i] - 1LL* d.size(a) * d.size(b);
      d.merge(a,b);
    }
  }

  dump(ans);
  rep_auto(i,ans){
    cout << i << endl;
  }



}
