#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

vector<long long> enum_divisors(long long N){
  vector<long long> res;
  for (long long i=1; i*i <= N; ++i){
    if (N%i==0){
      res.push_back(i);
      if (N/i != i) res.push_back(N/i);
    }
  }
  return res;
}
