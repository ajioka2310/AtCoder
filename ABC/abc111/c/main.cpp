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

vector<pair_int> check(v1i32 &ls){
  map<int,int> dict;
  rep(i,ls.size()){
    if (!dict.count(ls[i])) dict[ls[i]] = 1;
    else dict[ls[i]]++;
  }
  vector<pair_int> tmp;
  for(auto &[key,value]: dict){
    tmp.push_back({value,key});
  }
  sort(all(tmp));
  int n = tmp.size();
  if (n==1){
    return {{tmp[n-1].second,ls.size()-tmp[n-1].first},{0,ls.size()}};
  }
  else{
    return {
        {tmp[n-1].second,ls.size()-tmp[n-1].first},
        {tmp[n-2].second,ls.size()-tmp[n-2].first}
      };
  }
}

int main(){
  int N; cin>>N;
  v1i32 A(N/2,0),B(N/2,0);
  rep(i,N){
    if (i%2==0) cin>>A[i/2];
    else cin>>B[i/2];
  }
  sort(all(A));
  sort(all(B));
  dump(A,B);
  vector<pair_int> p_a = check(A);
  vector<pair_int> p_b = check(B);
  dump(p_a,p_b);
  if (p_a[0].first!=p_b[0].first){
    cout << p_a[0].second+p_b[0].second << endl;
  }
  else{
    cout << min(p_a[1].second+p_b[0].second,p_a[0].second+p_b[1].second) << endl;
  }
}
