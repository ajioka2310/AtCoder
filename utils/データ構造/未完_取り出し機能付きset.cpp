#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

#define td typedef
#define int ll

td long long ll;
td double db;
td pair<int, int> pi;
td vector<int> vi;
td vector<bool> vb;
td vector<string> vs;
td vector<char> vc;
td vector<vector<int>> vvi;
td vector<pi> vp;
td priority_queue<int> pq;
td priority_queue<int, vector<int>, greater<int>> pqg;

#define uset unordered_set
#define umap unordered_map
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define rep1(a) for (int i = 0; i < (int)a; i++)
#define rep2(i, a) for (int i = 0; i < (int)a; i++)
#define rep3(i, a, b) for (int i = a; i < (int)b; i++)
#define rep4(i, a, b, c) for (int i = a; i < (int)b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define cbit(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define elif else if
#define el endl
#define printa(a) cout << (a) << endl
#define debag(a) cout << #a << " : " << (a) << endl
#define sortv(v) sort(all(v))
#define ff first
#define ss second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dx8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int inf = (1LL << 61);

// istream &operator>>(istream &is, modint998244353 &a) {
//     long long v;
//     is >> v;
//     a = v;
//     return is;
// }
// ostream &operator<<(ostream &os, const modint998244353 &a) {
//     return os << a.val();
// }
// istream &operator>>(istream &is, modint1000000007 &a) {
//     long long v;
//     is >> v;
//     a = v;
//     return is;
// }
// ostream &operator<<(ostream &os, const modint1000000007 &a) {
//     return os << a.val();
// }
// template <int m>
// istream &operator>>(istream &is, static_modint<m> &a) {
//     long long v;
//     is >> v;
//     a = v;
//     return is;
// }
// template <int m>
// istream &operator>>(istream &is, dynamic_modint<m> &a) {
//     long long v;
//     is >> v;
//     a = v;
//     return is;
// }
// template <int m>
// ostream &operator<<(ostream &os, const static_modint<m> &a) {
//     return os << a.val();
// }
// template <int m>
// ostream &operator<<(ostream &os, const dynamic_modint<m> &a) {
//     return os << a.val();
// }
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &e : v) is >> e;
    return is;
}
template <class T>
istream &operator>>(istream &is, vector<vector<T>> &v) {
    for (auto &e : v)
        for (auto &c : e) is >> c;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &e : v) os << e << ' ';
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto &e : v) {
        for (auto &c : e) os << c << ' ';
        os << endl;
    }
    return os;
}

void yesno(bool a) {
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

template <typename T>
T power(T x, ll n) {
    T res = 1;
    while (n > 0) {
        if (n & 1) res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

ll ceil(ll x, ll y) {
    return (x + y - 1) / y;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
T sum_v(vector<T> a) {
    T sum = 0;
    for (auto i : a) {
        sum += i;
    }
    return sum;
}

template <typename T>
vector<T> acc(vector<T> &v) {
    vector<T> res(v.size());
    for (int i = 0; i < (int)v.size(); i++) {
        res[i] = i > 0 ? res[i - 1] + v[i] : v[0];
    }
    return res;
}
template <typename T>
vector<vector<T>> acc(vector<vector<T>> &v) {
    int h = v.size(), w = v[0].size();
    cout << h << " " << w << el;
    vector<vector<T>> res(h, vector<T>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            res[i][j] = v[i][j];
            if (i) res[i][j] += res[i - 1][j];
            if (j) res[i][j] += res[i][j - 1];
            if (i > 0 && j > 0) res[i][j] -= res[i - 1][j - 1];
        }
    }
    return res;
}

template <typename T>
int bit_count(T p) {
    int cnt = 0;
    rep(i, 64) {
        if ((ll(p) & ll(1)) == 1) {
            cnt++;
        }
        p >>= 1;
    }
    return cnt;
}

template <typename T>
bool is_bit_0(T p, int i) {
    return ((p >> i) & 1LL) == 0;
}

const double pi_val = 3.14159265358979323846;
const int MOD = 998244353;
// using mint = modint998244353;

// const int MOD = 1000000007;
// using mint = modint1000000007;

// using mint = static_modint<1000000009>;
// using mint = dynamic_modint<1000000009>;

// typedef vector<mint> vm;
// typedef vector<vector<mint>> vvm;
// typedef vector<vector<vector<mint>>> vvvm;
////////////////////////////////////////////////////////////////////////////////////////////
/** structure: 2-3 tree
 * available for both set and multiple set (see constructor)
 * every method works in O(logn)
 * test: https://judge.yosupo.jp/submission/105334
 *
 */

template <class T>
class twothreetree {
   private:
    struct node {
        node *parent = nullptr;
        unsigned char position;
        unsigned char n = 0;
        unsigned size = 0;
        T keys[2];
        node *children[3] = {nullptr, nullptr, nullptr};
        node() {
        }

        unsigned char lb(T key) {
            for (unsigned char i = 0; i < n; i++)
                if (key <= keys[i]) return i;
            return n;
        }

        unsigned char ub(T key) {
            for (unsigned char i = 0; i < n; i++)
                if (key < keys[i]) return i;
            return n;
        }

        void insert(unsigned char i, T key, node *child = nullptr) {
            if (n < 2) {
                if (i == 0) {
                    keys[1] = keys[0];
                    children[2] = children[1];
                }
                keys[i] = key;
                children[i + 1] = child;
                n++;
                coordinate();
                if (parent == nullptr) return;
                parent->sizeIncrement();
                return;
            }
            node *newNode = new node();
            T newKey;
            if (i == 0) {
                newNode->keys[0] = keys[1];
                newNode->children[0] = children[1];
                newNode->children[1] = children[2];
                newKey = keys[0];
                keys[0] = key;
                children[1] = child;
            } else if (i == 1) {
                newNode->keys[0] = keys[1];
                newNode->children[0] = child;
                newNode->children[1] = children[2];
                newKey = key;
            } else {
                newNode->keys[0] = key;
                newNode->children[0] = children[2];
                newNode->children[1] = child;
                newKey = keys[1];
            }
            children[2] = nullptr;
            newNode->n = 1;
            n = 1;
            newNode->coordinate();
            coordinate();
            if (parent == nullptr) {
                node *newRoot = new node();
                newRoot->keys[0] = newKey;
                newRoot->children[0] = this;
                newRoot->children[1] = newNode;
                newRoot->n = 1;
                newRoot->coordinate();
                return;
            }
            parent->insert(position, newKey, newNode);
        }

        void erase(unsigned char i) {
            delete children[i + 1];
            children[i + 1] = nullptr;
            if (n == 2) {
                if (i == 0) {
                    keys[0] = keys[1];
                    children[1] = children[2];
                    children[2] = nullptr;
                }
                n--;
                this->coordinate();
                if (parent == nullptr) return;
                parent->sizeDecrement();
                return;
            }
            if (parent == nullptr) {
                n--;
                size--;
                return;
            }
            if (position > 0) {
                node *leftNode = parent->children[position - 1];
                if (leftNode->n == 2) {
                    keys[0] = parent->keys[position - 1];
                    parent->keys[position - 1] = leftNode->keys[1];
                    children[1] = children[0];
                    children[0] = leftNode->children[2];
                    leftNode->children[2] = nullptr;
                    leftNode->n = 1;
                    n = 1;
                    leftNode->coordinate();
                    coordinate();
                    if (parent == nullptr) return;
                    parent->sizeDecrement();
                    return;
                }

                leftNode->keys[1] = parent->keys[position - 1];
                leftNode->children[2] = children[0];
                leftNode->n = 2;
                leftNode->coordinate();
                parent->erase(position - 1);
                return;
            }
            node *rightNode = parent->children[1];
            if (rightNode->n == 2) {
                keys[0] = parent->keys[0];
                parent->keys[0] = rightNode->keys[0];
                children[1] = rightNode->children[0];
                rightNode->keys[0] = rightNode->keys[1];
                rightNode->children[0] = rightNode->children[1];
                rightNode->children[1] = rightNode->children[2];
                rightNode->children[2] = nullptr;
                rightNode->n = 1;
                n = 1;
                rightNode->coordinate();
                coordinate();
                if (parent == nullptr) return;
                parent->sizeDecrement();
                return;
            }
            rightNode->keys[1] = rightNode->keys[0];
            rightNode->keys[0] = parent->keys[position];
            rightNode->children[2] = rightNode->children[1];
            rightNode->children[1] = rightNode->children[0];
            rightNode->children[0] = children[0];
            rightNode->n = 2;
            rightNode->coordinate();
            parent->children[0] = rightNode;
            parent->children[1] = this;
            rightNode->position = 0;
            parent->erase(0);
        }

        void sizeIncrement() {
            size++;
            if (parent != nullptr) parent->sizeIncrement();
        }

        void sizeDecrement() {
            size--;
            if (parent != nullptr) parent->sizeDecrement();
        }

        void coordinate() {
            size = n;
            if (children[0] == nullptr) return;
            for (unsigned char i = 0; i <= n; i++) {
                size += children[i]->size;
                children[i]->parent = this;
                children[i]->position = i;
            }
        }
    };
    node *root;
    bool isForMulti;

   public:
    twothreetree(bool forMultiSet = false) {
        root = new node();
        isForMulti = forMultiSet;
    }
    unsigned lower_bound(T key) {
        node *presentNode = root;
        unsigned res = 0;
        while (presentNode->children[0] != nullptr) {
            unsigned char i = presentNode->lb(key);
            for (unsigned char j = 0; j < i; j++)
                res += presentNode->children[j]->size;
            res += i;
            presentNode = presentNode->children[i];
        }
        return res + presentNode->lb(key);
    }

    unsigned upper_bound(T key) {
        node *presentNode = root;
        unsigned res = 0;
        while (presentNode->children[0] != nullptr) {
            unsigned char i = presentNode->ub(key);
            for (unsigned char j = 0; j < i; j++)
                res += presentNode->children[j]->size;
            res += i;
            presentNode = presentNode->children[i];
        }
        return res + presentNode->ub(key);
    }

    bool insert(T key) {
        node *presentNode = root;
        unsigned char i;
        while (presentNode->children[0] != nullptr) {
            i = presentNode->lb(key);
            if (!isForMulti && i < presentNode->n &&
                presentNode->keys[i] == key)
                return false;
            presentNode = presentNode->children[i];
        }
        i = presentNode->lb(key);
        if (!isForMulti && i < presentNode->n && presentNode->keys[i] == key)
            return false;
        presentNode->insert(i, key);
        if (root->parent != nullptr) {
            root = root->parent;
        }
        return true;
    }

    bool erase(T key) {
        node *presentNode = root;
        unsigned char i;
        while (presentNode->children[0] != nullptr) {
            i = presentNode->lb(key);
            if (i < presentNode->n && presentNode->keys[i] == key) break;
            presentNode = presentNode->children[i];
        }
        if (presentNode->children[0] == nullptr) {
            i = presentNode->lb(key);
            if (i < presentNode->n && presentNode->keys[i] == key) {
                presentNode->erase(i);
                if (root->n == 0 && root->children[0] != nullptr) {
                    root = root->children[0];
                    delete root->parent;
                    root->parent = nullptr;
                }
                return true;
            }
            return false;
        }
        node *eraseNode = presentNode->children[i + 1];
        while (eraseNode->children[0] != nullptr)
            eraseNode = eraseNode->children[0];
        presentNode->keys[i] = eraseNode->keys[0];
        eraseNode->erase(0);
        if (root->n == 0) {
            root = root->children[0];
            delete root->parent;
            root->parent = nullptr;
        }
        return true;
    }

    T get(unsigned i) {
        if (i < 0) i += root->size;
        node *presentNode = root;
        while (presentNode->children[0] != nullptr) {
            unsigned char j = 0;
            while (i >= presentNode->children[j]->size + 1) {
                i -= presentNode->children[j]->size + 1;
                j++;
            }
            if (i == presentNode->children[j]->size) {
                return presentNode->keys[j];
            }
            presentNode = presentNode->children[j];
        }
        return presentNode->keys[i];
    }

    unsigned size() {
        return root->size;
    }

    unsigned count(T key) {
        return upper_bound(key) - lower_bound(key);
    }

    T operator[](unsigned i) {
        return get(i);
    }
};

#ifdef DEFINED_ONLY_IN_LOCAL
#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
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

/////////////////////////////////////////////////////////////////////////////////////////////////////
signed main() {
    twothreetree<int> st(true);
    
    st.insert(1);
    st.insert(3);
    st.insert(5);
    // dump(st);


}  