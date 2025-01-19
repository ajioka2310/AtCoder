// abc119 C - Synthetic Kadomatsu
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


const int INF=INT32_MAX/2;
const int MOD=1e9+7;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
int main(){
  int N,A,B,C; cin>>N>>A>>B>>C;
  vec L(N,0); rep(i,N) cin>>L[i];
  int res = INF;
  rep_bit(bit,2*N){
    vec ls(N,0);
    rep(i,N){
      if(bit&(1<<i)&&bit&(1<<i+N)) ls[i] = 0;
      else if(!(bit&(1<<i))&&bit&(1<<i+N)) ls[i] = 1;
      else if(bit&(1<<i)&&!(bit&(1<<i+N))) ls[i] = 2;
      else ls[i] = 3;
    }
    vec ls_A,ls_B,ls_C;
    rep(i,N){
      if (ls[i]==1) ls_A.push_back(L[i]);
      else if (ls[i]==2) ls_B.push_back(L[i]);
      else if (ls[i]==3) ls_C.push_back(L[i]);
    }

    if (ls_A.empty()||ls_B.empty()||ls_C.empty()) continue;
    int ans = 0;

    // A の作成
    int tmp_a = ls_A[0];
    if (ls_A.size()>1){
      krep(i,1,ls_A.size()){
        tmp_a += ls_A[i];
        ans += 10;
      } 
    }
    ans += abs(tmp_a-A);
    // B の作成
    int tmp_b = ls_B[0];
    if (ls_B.size()>1){
      krep(i,1,ls_B.size()){
        tmp_b += ls_B[i];
        ans += 10;
      } 
    }
    ans += abs(tmp_b-B);
    // C の作成
    int tmp_c = ls_C[0];
    if (ls_C.size()>1){
      krep(i,1,ls_C.size()){
        tmp_c += ls_C[i];
        ans += 10;
      } 
    }
    ans += abs(tmp_c-C);
    if (res>ans){
      dump(ls_A,ls_B,ls_C);
      dump(ans);
    }
    res = min(res,ans);
  }

  cout << res << endl;
}
