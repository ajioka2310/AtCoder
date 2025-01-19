#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

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


const int MAX_N = 5000;
const long long MOD = 1;

long long Com[MAX_N][MAX_N];

/* init_nCk:二項係数のための前処理
    計算量:O(MAX_N*MAX_N)
*/
void init_nCk() {
    // memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_N; j++) {
            Com[i][j] = (Com[i - 1][j - 1] + Com[i - 1][j])%MOD;
        }
    }
}

/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/
long long nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return Com[n][k];
}

int main(){
    init_nCk();
    cpp_dump(nCk(5,2));
}