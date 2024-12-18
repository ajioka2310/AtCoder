#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long
#define vec vector<int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* rep(i, n) {
        cout << i;
  }
*/
/* for (auto& x: X) {
        cin >> x;
    }
*/

#define krep(i, k, n) for (int i = k; i < (int)(n); i++)


int main() {
  int a,b,c,cnt;
  cin >> a >> b >> c;
  cnt = 0;
  krep(i, a, b+1){
    if (c%i==0){
      cnt +=1;
    }
  }
  cout << cnt << endl;
}
