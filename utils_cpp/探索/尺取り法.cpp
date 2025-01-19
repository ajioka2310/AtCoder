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


int main(){
  int n; cin >> n;
  int right = 0;     
  for (int left = 0; left < n; ++left) {
      while (right < n && (right を 1 個進めたときに条件を満たす)) {
          /* 実際に right を 1 進める */
          // ex: sum += a[right];
          ++right;
      }

      /* break した状態で right は条件を満たす最大なので、何かする */
      // ex: res += (right - left);

      /* left をインクリメントする準備 */
      // ex: if (right == left) ++right;
      // ex: else sum -= a[left];
  }

}

int main() {
  int n, k;
  cin >> n >> k;
  bool check_zero = false;
  //元となるキューpと、尺取り中の列q
  queue<int> p, q;
  int ans = 0;
  //基準となる処理（尺取り中の列の積は？）
  ll criterion = 1;
  while (p.size() > 0) {
    int now = p.front();
    p.pop();
    q.push(now);
    criterion *= now;
    //次の数を入れていい状態になるまでqを整理
    while (criterion > k && q.size() > 0) {
      int rm = q.front();
      q.pop();
      criterion /= rm;
    }
    ans = max(ans, int(q.size()));
  }
  cout << ans << endl;
}