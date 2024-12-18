// abc381 E - 11/22 Subsequence
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

// x以下の範囲における最大値。
i64 hoge(auto &SLA, i64 X){
  i64 L = 0;
  i64 R = SLA.size();
  while(R-L>1){
    i64 mid = (L+R)/2;
    if (SLA[mid]<=X) L = mid;
    else R = mid;
  }
  return L;
}

int main(){
  i64 N,Q; cin>>N>>Q;
  string S; cin>>S;
  
  v1i64 C1(N+1),C2(N+1),SLA;
  SLA.push_back(-1);
  rep(i,N){
    if (S[i]=='1') C1[i+1]=1;
    else if (S[i]=='2') C2[i+1]=1;
    else SLA.push_back(i+1);
  }
  SLA.push_back(909090909090);
  krep(i,1,N+1){
    C1[i] += C1[i-1];
    C2[i] += C2[i-1];
  }
  dump(N,Q);
  dump(C1);
  dump(C2);
  dump(SLA);

  rep(i,Q){
    i64 L,R; cin>>L>>R;
    // 探索範囲：含まれるスラッシュの範囲について。[L,R)
    i64 now_left = lower_bound(all(SLA),L) - SLA.begin();
    i64 now_right = upper_bound(all(SLA),R) - SLA.begin();
    dump(L,R);
    dump(now_left,now_right);
    if (now_left==now_right){
      cout << 0 << endl;
      continue;
    }

    // 最大値を探索
    pair<i64,i64> score_left = {C1[SLA[now_left]-1]-C1[L-1],C2[R]-C2[SLA[now_left]]};
    while(now_right-now_left>1){
      i64 mid = (now_right+now_left)/2;
      pair<i64,i64> score_mid = {C1[SLA[mid]-1]-C1[L-1],C2[R]-C2[SLA[mid]]};
      if (min(score_left.first,score_left.second)<=min(score_mid.first,score_mid.second)) now_left = mid;
      else now_right = mid;
    }
    dump(score_left);

    i64 res = min(score_left.first,score_left.second);
    cout << res*2+1 << endl;
  }
}
