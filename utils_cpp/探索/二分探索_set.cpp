#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>

#define graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()

#include "/workspaces/AtCoder/cpp-dump/cpp-dump.hpp"
namespace cp = cpp_dump;

int func1(){
  set<int> v = {0,1,3,5,99999999};
  rep(i,7){
    decltype(v)::iterator iter_lower = v.lower_bound(i);
    int idx_lower = distance(v.begin(),iter_lower);
    decltype(v)::iterator iter_upper = v.upper_bound(i);;
    int idx_upper = distance(v.begin(),iter_upper);
    cpp_dump(i,v);
    cpp_dump(*iter_lower,*iter_upper);
    cpp_dump(*prev(iter_lower),*prev(iter_upper));
    cpp_dump(*next(iter_lower),*next(iter_upper));
    // *prev(iter_upper) = x 以下の最大要素
    // *prev(iter_upper) = x 未満の最大要素
  }
}





int main(){
  func1();
  cout << endl;
}