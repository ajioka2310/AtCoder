// abc119 D - Lazy Faith
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


const int INF_INT=INT32_MAX/2;
const int MOD=10007;
const ll INF_LL = 1e15;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

int main(){
  int A,B,Q; cin>>A>>B>>Q;
  llvec S(A+1,-1e12); rep(i,A) cin>>S[i+1];
  llvec T(B+1,-1e12); rep(i,B) cin>>T[i+1];
  llvec X(Q,0); rep(i,Q) cin>>X[i];
  S.push_back(1e12);
  T.push_back(1e12);
  dump(S,T,X);
  rep(i,Q){
    ll x = X[i];
    int idx_s = lower_bound(all(S),x) - S.begin();
    int idx_t = lower_bound(all(T),x) - T.begin();
    dump(x,idx_s,idx_t);
    int idx_s_left = idx_s-1;
    int idx_s_right = idx_s;
    int idx_t_left = idx_t-1;
    int idx_t_right = idx_t;
    ll res = INF_LL;
    // ll
    res = min(res,x-min(T[idx_t_left],S[idx_s_left]));
    dump("ll",res);
    // rr
    res = min(res,max(T[idx_t_right],S[idx_s_right])-x);
    dump("rr",res);

    // r->l 2ケース
    // rs -> lt
    ll tmp = 0;
    if (idx_s_right!=S.size()-1&&idx_t_left!=0){
      tmp = (S[idx_s_right] -x) +(S[idx_s_right]-T[idx_t_left]);
      res = min(res, tmp);
      dump("rslt",tmp);
    }
    // rt -> ls
    if (idx_t_right!=T.size()-1&&idx_s_left!=0){
      tmp =  (T[idx_t_right] -x) +(T[idx_t_right]-S[idx_s_left]);
      res = min(res,tmp);
      dump("rtls",tmp);
    }
    // ls -> rt
    if (idx_s_left!=0&&idx_t_right!=T.size()-1){
      tmp =  (x - S[idx_s_left]) +(T[idx_t_right]-S[idx_s_left]);
      res = min(res,tmp);
      dump("lsrt",tmp);
    }
    // lt -> rs
    if (idx_t_left!=0&&idx_s_right!=S.size()-1){
      tmp =  (x - T[idx_t_left]) +(S[idx_s_right]-T[idx_t_left]);
      res = min(res,tmp);
      dump("ltrs",tmp);
    }
    cout << res << endl;

  }
  

  
}
