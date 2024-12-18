#include <bits/stdc++.h>
#include <cmath>
// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;
using namespace std;

#define ll long long
#define vec vector<int>
#define Graph vector<vector<int>>
// vectore

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

#define all(v) v.begin(), v.end()

/*
%d : int
%.5f : 下5桁
%s : string
*/ 

void print_vec(vec v) {
    rep(i, (int)v.size()) {
        cout << v.at(i);
    }
    cout << endl;
}


int main() {
    // Graph ls(4, vec(13,0));
    int ls[4][13] = {{}};

    int n;
    cin >> n;

    rep(i,n){ 
        char div;
        int num,div_num;
        cin >> div >> num;
        if(div=='S'){
            div_num = 0;
        }
        else if(div=='H'){
            div_num = 1;
        }
        else if (div=='C'){
            div_num = 2;
        }
        else{
            div_num = 3;
        }
        ls[div_num][num-1] = 1;
    }

    char conv[4] = {'S','H','C','D'};

    rep(i,4){
        rep(j,13){
            if (ls[i][j]==0){
                printf("%c %d\n",conv[i],j+1);
            }
        }
    }

}
