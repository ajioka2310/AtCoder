// abc340 C - Divide and Divide
#pragma region Macros
#ifdef DEFINED_ONLY_IN_LOCAL
#include "/workspaces/AtCoder/cpp-dump/cpp-dump.hpp"
// <次のセクションの内容はここに追加する>
#define dump(...) cpp_dump(__VA_ARGS__)
namespace cp = cpp_dump;
CPP_DUMP_SET_OPTION_GLOBAL(max_line_width, 80);
CPP_DUMP_SET_OPTION_GLOBAL(log_label_func, cp::log_label::filename());
CPP_DUMP_SET_OPTION_GLOBAL(enable_asterisk, true);
#else
#define dump(...)
#define CPP_DUMP_SET_OPTION(...)
#define CPP_DUMP_SET_OPTION_GLOBAL(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
#endif

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using i64 = long long;
using ll = long long;

using f80 = long double;
using v1i32 = vector<int>;
using v1i64 = vector<i64>;
using v1str = vector<string>;
using v2i32 = vector<v1i32>;
using v2i64 = vector<v1i64>;
using v2str = vector<v1str>;
using v3i32 = vector<v2i32>;
using v3i64 = vector<v2i64>;
using pair_int = pair<int, int>;
// macros
#define overload5(a, b, c, d, e, name, ...) name
#define overload4(a, b, c, d, name, ...) name
// for
#define REP0(n) for (ll jidlsjf = 0; jidlsjf < n; ++jidlsjf) // ループ変数が必要ない場合。
#define REP1(i, n) for (ll i = 0; i < (n); ++i)
#define REP2(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP3(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
// reverse for
#define per0(n) for (int jidlsjf = 0; jidlsjf < (n); ++jidlsjf)
#define per1(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define per2(i, a, b) for (ll i = (a) - 1; i >= b; --i)
#define per3(i, a, b, c) for (ll i = (a) - 1; i >= (b); i -= (c))
#define per(...) overload4(__VA_ARGS__, per3, per2, per1, per0)(__VA_ARGS__)
// enumerate
#define fore0(a) rep(a.size())
#define fore1(i, a) for (auto &&i : a)
#define fore2(a, b, v) for (auto &&[a, b] : v)
#define fore3(a, b, c, v) for (auto &&[a, b, c] : v)
#define fore4(a, b, c, d, v) for (auto &&[a, b, c, d] : v)
#define fore(...) overload5(__VA_ARGS__, fore4, fore3, fore2, fore1, fore0)(__VA_ARGS__)
// bit for
#define rep_bit(bit, n) for (int bit = 0; bit < (1 << n); ++bit)

// short
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
// basic functinon
#define si(c) (i64)(c).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

// ソート
#define SORT(v) sort(all(v))
#define REV(v) reverse(all(v))
// 2分探索
// x<=c[i]を満たす最小インデックス
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define lbg(c, x) distance((c).begin(), lower_bound(all(c), (x), greater{}))
// x<c[i]を満たす最小インデックス
// ub-1 <-> c[i]<=xを満たす最大インデックス
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define ubg(c, x) distance((c).begin(), upper_bound(all(c), (x), greater{}))

// 配列計算
#define max_idx(a) max_element(all(a)) - a.begin()
#define min_idx(a) min_element(all(a)) - a.begin()
#define max_value(A) A[max_idx(A)]
#define min_value(A) A[min_idx(A)]
#define sum_values(A) reduce(all(A))

// 変数
#define INT(...)   \
	i64 __VA_ARGS__; \
	IN(__VA_ARGS__)
#define INTd(...)  \
	i64 __VA_ARGS__; \
	IN2(__VA_ARGS__)
#define STR(...)      \
	string __VA_ARGS__; \
	IN(__VA_ARGS__)
#define CHR(...)    \
	char __VA_ARGS__; \
	IN(__VA_ARGS__)
#define DBL(...)      \
	double __VA_ARGS__; \
	IN(__VA_ARGS__)
// 配列
#define VEC(type, name, size) \
	vector<type> name(size);    \
	IN(name)
#define VECd(type, name, size) \
	vector<type> name(size);     \
	IN2(name)
#define VEC2(type, name1, name2, size)   \
	vector<type> name1(size), name2(size); \
	for (int i = 0; i < size; i++)         \
	IN(name1[i], name2[i])
#define VEC2d(type, name1, name2, size)  \
	vector<type> name1(size), name2(size); \
	for (int i = 0; i < size; i++)         \
	IN2(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size)         \
	vector<type> name1(size), name2(size), name3(size); \
	for (int i = 0; i < size; i++)                      \
	IN(name1[i], name2[i], name3[i])
#define VEC3d(type, name1, name2, name3, size)        \
	vector<type> name1(size), name2(size), name3(size); \
	for (int i = 0; i < size; i++)                      \
	IN2(name1[i], name2[i], name3[i])
#define VEC4(type, name1, name2, name3, name4, size)               \
	vector<type> name1(size), name2(size), name3(size), name4(size); \
	for (int i = 0; i < size; i++)                                   \
		IN(name1[i], name2[i], name3[i], name4[i]);
#define VEC4d(type, name1, name2, name3, name4, size)              \
	vector<type> name1(size), name2(size), name3(size), name4(size); \
	for (int i = 0; i < size; i++)                                   \
		IN2(name1[i], name2[i], name3[i], name4[i]);
#define VV(type, name, h, w)                     \
	vector<vector<type>> name(h, vector<type>(w)); \
	IN(name)
#define VVd(type, name, h, w)                    \
	vector<vector<type>> name(h, vector<type>(w)); \
	IN2(name)
// scan
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S>
void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T>
void scan(vector<T> &);
template <class T>
void scan(vector<T> &a)
{
	for (auto &i : a)
		scan(i);
}
template <class T>
void scan(T &a) { cin >> a; }
// IN定義
void IN() {}
void IN2() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail)
{
	scan(head);
	IN(tail...);
}
template <class Head, class... Tail>
void IN2(Head &head, Tail &...tail)
{
	scan(head);
	--head;
	IN2(tail...);
}
// 出力テンプレート
template <typename T>
void print(T out){
	cout << out << "\n";
}
template <typename Iterable>
void print_all(const Iterable& container) {
    for (const auto& elem : container) {
        cout << elem << " ";
    }
    cout << endl;
}

// 反時計周りに 90 度回転
template <typename T>
void rot(vector<vector<T>> &v)
{
	if (empty(v))
		return;
	int n = v.size(), m = v[0].size();
	vector<vector<T>> res(m, vector<T>(n));
	rep(i, n) rep(j, m) res[m - 1 - j][i] = v[i][j];
	v.swap(res);
}

// 要素の出現回数
vector<int> counter(const vector<int> &v, int max_num = -1)
{
	if (max_num == -1)
		max_num = max_value(v);
	vector<int> res(max_num + 1);
	fore(e, v) res[e]++;
	return res;
}
// 累積和
template <typename T>
vector<T> RUI(const vector<T> &v)
{
	vector<T> res(v.size() + 1);
	for (int i = 0; i < v.size(); i++)
		res[i + 1] = res[i] + v[i];
	return res;
}
template <class T>
bool chmax(T &a, const T &b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return 1;
	}
	return 0;
}

template <typename T>
class pqasc : public priority_queue<T, vector<T>, greater<T>>
{
};
template <typename T>
class pqdesc : public priority_queue<T, vector<T>, less<T>>
{
};

constexpr i64 INF = (1LL << 60);
const int MOD = 998244353;

inline string YESNO(bool cond) { return cond ? "YES" : "NO"; }
inline string yesno(bool cond) { return cond ? "yes" : "no"; }
inline string YesNo(bool cond) { return cond ? "Yes" : "No"; }

bool cmp(pair_int a, pair_int b) { return a.second < b.second; }
using mint = modint998244353;
#pragma endregion

int main()
{
	INT(N);
	ll res = 0;
	deque<ll> que;
	que.pf(N);
	while(que.size()){
		ll now = que.front(); que.ppf();
		if (now/2>1) que.pf(now/2);
		if ((now+1)/2>1) que.pf((now+1)/2);
		res += now;
		dump(now);
	}
	print(res);
}
