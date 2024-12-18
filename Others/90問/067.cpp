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
#define rep_inv(i,n) for (int i=n-1; i>=0; --i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
const int INF=INT32_MAX/2;
const int MOD=10007;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}



ll bit8_2_bit10 (string N){
  ll ans = 0;
  ll x = 1;
  rep_inv(i,N.size()){
    ans += (N[i]-'0') * x;
    x *= 8;
  }
  return ans;
}

string bit10_2_bit9(ll bit10){
  if(bit10==0){
    return "0";
  }
  string ans;
  while (bit10>0)
  {
    int mod = bit10%9;
    bit10 = (bit10-mod)/9;
    ans = char(mod+'0') + ans;
  }
  return ans;
}


int main(){
  string N;cin>>N;
  int K; cin>>K;
  
  rep(i,K){
    // 8bit to 10bit
    ll bit10 = bit8_2_bit10(N);
    string bit9 = bit10_2_bit9(bit10);
    rep(j,bit9.size()){
      if(bit9[j]=='8') bit9[j]='5';
    }
    N = bit9;

  }

  cout << N << endl;

}
