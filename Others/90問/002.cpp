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
  if (N%2==1) return 0;
  vector<string> ans;
  dump(ans);

  rep_bit(bit,N){
    vector<char> ls(N,'(');
    int l = 0;
    int r = 0;
    bool flg = true;
    rep(i,N){
      if (bit&(1<<i)) ls[i] = ')';
      if (ls[i]=='(') l+=1;
      else r+=1;
      if (r>l) flg = false;
    }
    if (r!=l) flg = false;
    // dump(ls,flg,bit);
    if (flg) {
      string tmp(all(ls));
      ans.push_back(tmp);
    }
  }
  sort(all(ans));
  rep(i,ans.size()){
    cout << ans[i] << endl;
  }
}
