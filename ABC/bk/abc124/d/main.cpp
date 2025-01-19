// abc124 D - Handstand
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
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
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
  int N,K; cin>>N>>K;
  string S; cin>>S;
  S = S+'e';
  llvec ls;
  if (S[0]=='0') ls.push_back(0);
  ll cnt = 1;
  rep(i,S.size()-1){
    if (S[i]==S[i+1]) cnt++;
    else {
      ls.push_back(cnt);
      cnt = 1;
    }
  }
  if (S[S.size()-2]=='0') ls.push_back(0);
  llvec ls_cumsum(ls.size()+1,0);
  krep(i,1,ls_cumsum.size()){
    ls_cumsum[i] += ls_cumsum[i-1]+ ls[i-1];
  }
  dump(ls);
  dump(ls_cumsum);

  ll res = 0;
  if ((ls.size()-1)/2<=K){
    cout << ls_cumsum[ls_cumsum.size()-1] << endl;
    return 0;
  }
  rep(left,ls_cumsum.size()-2*K-1){
    if (left%2==0){
      int right = left + 2*K + 1;
      dump(ls_cumsum.size(),left,right);
      dump(ls_cumsum[right]-ls_cumsum[left]);
      res = max(res, ls_cumsum[right]-ls_cumsum[left]);
    }

  }
  cout << res << endl;
}
