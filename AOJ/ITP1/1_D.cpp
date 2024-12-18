#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long


int main() {
  int S;

  cin >> S;
  int H = S/3600;
  int M = (S - H*3600)/60;
  int Sec = (S - H*3600 - M*60);
  cout << H << ':' << M << ':' << Sec << endl;
}
