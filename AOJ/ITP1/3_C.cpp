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



int main() {
  while (true){
    int x,y;
    cin >> x >> y;
    if (x+y==0){
      break;
    }
    else{
      if (x>y){
        cout << y << ' ' << x << endl;
      }
      else {
        cout << x << ' ' << y << endl;
      }
    }
  }
  
}
