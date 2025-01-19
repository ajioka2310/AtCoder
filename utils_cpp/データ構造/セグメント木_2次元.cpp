#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
#define INF inf
#define def INF
using V = int;
V comp(V& l, V& r) { return min(l, r); };
struct SegTree { //[l,r)
	int NV;
	vector<V> val;
	void init(int n) {
		NV = 1;
		while (NV < n) NV *= 2;
		val = vector<V>(NV * 2, def);
	}
	V get(int x, int y, int l, int r, int k) {
		if (r <= x || y <= l) return def; if (x <= l && r <= y)return val[k];
		auto a = get(x, y, l, (l + r) / 2, k * 2); auto b = get(x, y, (l + r) / 2, r, k * 2 + 1); return comp(a, b);
	}
	V get(int x, int y) { return get(x, y, 0, NV, 1); }
	void update(int i, V v) { i += NV; val[i] = v; while (i > 1)i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]); }
	void add(int i, V v) { update(i, val[i + NV] + v); }
	V operator[](int x) { assert(0 <= x and x < NV); return val[x + NV]; }
};

struct Healthy2DSegTreeVer2 {
	int NV;
	vector<SegTree> st;
	vector<vector<int>> index;

	void init(vector<vector<int>>& v) {
		int n = v.size();
		NV = 1; while (NV < n) NV *= 2;
		index.resize(2 * NV);
		rep(i, 0, n) fore(j, v[i]) index[i + NV].push_back(j);
		rrep(i, NV * 2 - 1, 1) {
			sort(index[i].begin(), index[i].end());
			index[i].erase(unique(index[i].begin(), index[i].end()), index[i].end());
			fore(j, index[i]) index[i / 2].push_back(j);
		}
		st.resize(2 * NV);
		rep(i, 1, NV * 2) st[i].init(index[i].size());
	}
	void restupdate(int x, int y) {
		if (x == 0) return;
		assert(1 <= x);

		while (x) {
			int yy = lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
			assert(yy != index[x].size());
			assert(y == index[x][yy]);

			int x1 = x * 2;
			int yy1 = -1;
			int y1 = lower_bound(index[x1].begin(), index[x1].end(), y) - index[x1].begin();
			if (y1 == index[x1].size()) y1 = 0;
			else yy1 = index[x1][y1];


			int x2 = x * 2 + 1;
			int yy2 = -1;
			int y2 = lower_bound(index[x2].begin(), index[x2].end(), y) - index[x2].begin();
			if (y2 == index[x2].size()) y2 = 0;
			else yy2 = index[x2][y2];

			if (yy1 == y and yy2 == y) {
				V a = st[x1][y1];
				V b = st[x2][y2];
				st[x].update(yy, comp(a, b));
			}
			else if (yy1 == y) {
				V a = st[x1][y1];
				st[x].update(yy, a);
			}
			else if (yy2 == y) {
				V a = st[x2][y2];
				st[x].update(yy, a);
			}
			else assert(0);

			x /= 2;
		}
	}
	void update(int x, int y, V v) {
		assert(x < NV);
		x += NV;
		int yy = lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
		assert(yy != index[x].size());
		assert(y == index[x][yy]);
		st[x].update(yy, v);
		restupdate(x / 2, y);
	}
	void add(int x, int y, V v) {
		assert(x < NV);
		x += NV;
		int yy = lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
		assert(yy != index[x].size());
		assert(y == index[x][yy]);
		st[x].add(yy, v);
		restupdate(x / 2, y);
	}
	V get(int sx, int tx, int sy, int ty, int k, int l, int r) {
		assert(k < NV * 2);
		assert(l < r);
		if (r <= sx or tx <= l) return def;
		if (sx <= l and r <= tx) {
			int syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
			int tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
			return st[k].get(syy, tyy);
		}
		int md = (l + r) / 2;
		V le = get(sx, tx, sy, ty, k * 2, l, md);
		V ri = get(sx, tx, sy, ty, k * 2 + 1, md, r);
		return comp(le, ri);
	}
	V get(int sx, int tx, int sy, int ty) {
		return get(sx, tx, sy, ty, 1, 0, NV);
	}
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[101010], vis[101010];
Healthy2DSegTreeVer2 st;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	vector<vector<int>> idx(N);
	rep(i, 0, N) idx[i].push_back(A[i]);
	st.init(idx);
	rep(i, 0, N) st.update(i, A[i], i);

	int ans = 0;
	rep(i, 0, N) if (!vis[i]) {
		ans++;
		int cu = i;
		while (cu < N) {
			vis[cu] = 1;
			st.update(cu, A[cu], inf);

			cu = st.get(cu + 1, N, A[cu] + 1, inf);
		}
	}

	cout << ans << endl;
}





