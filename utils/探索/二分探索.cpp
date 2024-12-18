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

#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
namespace cp = cpp_dump;

int func1(){
  vec v = {1,3,5};
  sort(all(v));
  rep(i,7){
    decltype(v)::iterator iter_lower = lower_bound(all(v),i);
    int idx_lower = distance(v.begin(),iter_lower);
    decltype(v)::iterator iter_upper = upper_bound(all(v),i);
    int idx_upper = distance(v.begin(),iter_upper);
    cpp_dump(i,v);
    cpp_dump(binary_search(all(v),i),idx_lower,idx_upper);
  }
  // a <= vk を満たす最小INDEX
  // lower_bound(all(v),i) - v.begin();
  // vk < a となる最初のINDEX
  // upper_bound(all(v),i) - v.begin();

}

int func2(){
  vec v = {0,1,1,1,3};
  // sort(all(v));
  rep(i,5){
    int idx_lower = lower_bound(all(v),i) - v.begin();
    int idx_upper = upper_bound(all(v),i) - v.begin();
    cpp_dump(i,v);
    cpp_dump(binary_search(all(v),i),idx_lower,idx_upper);
  }
}



int main(){
  func1();
  cout << endl;
  func2();
}