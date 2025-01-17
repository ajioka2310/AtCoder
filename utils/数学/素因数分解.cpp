#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

vector<pair<long long,long long> > prime_factorize(long long N) {
  vector<pair<long long,long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
      long long ex = 0; // 指数
      // 割れる限り割り続ける
      while (N % a == 0) {
        ++ex;
        N /= a;
      }
      res.push_back({a, ex}); // その結果を push
  }
  if (N != 1) res.push_back({N, 1}); // 最後に残った数について
  return res;
}

