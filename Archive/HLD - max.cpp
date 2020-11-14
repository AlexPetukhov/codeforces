#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x)  ((int)x.size ())
#define all(x) (x).begin(), (x).end()
#define re return
#define mp make_pair
#define sqrt(x) sqrt (abs(x))
#define y0 y3451
#define y1 y4562
#define j0 j25624
#define j1 j45624
#define makeunique(x) sort(all(x)), (x).resize (unique(all(x)) - (x).begin())

typedef pair <int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef double D;
typedef long double ld;
typedef unsigned int uint;
typedef vector <string> vs;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;

template <class T> using _tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }
template <class T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }

#define filename ""

const D pi = acos(-1.);
const int N = 2e5 + 20;
const int inf = 1e9 + 7;

int n, m;
vi g[N];
int s[N], in[N], out[N];
vi e;

void dfs(int v, int pr = -1) {
    s[v] = 1;
    for (auto x : g[v])
        if (x != pr) {
            dfs(x, v);
            s[v] += s[x];
        }
    for (int i = 0; i < sz(g[v]); i++)
        if (g[v][i] != pr)
            if (g[v][0] == pr || s[g[v][i]] > s[g[v][0]]) swap(g[v][0], g[v][i]);
}

int pr[N], nxt[N];
int up[N][20];

void hld(int v, int prv = -1) {
    in[v] = sz(e);
    e.pb(v);
    if (prv == -1) { nxt[v] = v; pr[v] = -1; }
    for (auto x : g[v])
        if (x != prv) {
            if (2 * s[x] >= s[v]) nxt[x] = nxt[v];
            else nxt[x] = x;
            up[x][0] = pr[x] = v;
            for (int i = 1; i < 20; i++)
                if (up[x][i - 1] != -1)
                    up[x][i] = up[up[x][i - 1]][i - 1];
            hld(x, v);
        }
    out[v] = sz(e) - 1;
}

int t[4 * N];

bool ok(int x, int y) {
    re in[x] <= in[y] && out[y] <= out[x];
}

int lca(int x, int y) {
    if (ok(x, y)) re x;
    if (ok(y, x)) re y;
    for (int i = 19; i >= 0; i--) {
        if (up[x][i] == -1) continue;
        if (!ok(up[x][i], y)) x = up[x][i];
    }
    re up[x][0];
}

void upd(int v, int tl, int tr, int x, int pos) {
    if (tl == tr) { t[v] += x; re; }
    int c = (tl + tr) >> 1;
    if (pos > c) upd (2 * v + 2, c + 1, tr, x, pos);
    else upd (2 * v + 1, tl, c, x, pos);
    t[v] = max(t[2 * v + 2], t[2 * v + 1]);
}

int get (int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr) re -inf;
    if (l <= tl && tr <= r) re t[v];
    int c = (tl + tr) >> 1;
    re max(get(2 * v + 1, tl, c, l, r), get(2 * v + 2, c + 1, tr, l, r));
}

int jump (int x, int z) {
    int ans = -inf;
    while (in[nxt[x]] > in[z]) {
        ans = max(ans, get(0, 0, n - 1, in[nxt[x]], in[x]));
        x = pr[nxt[x]];
    }
    ans = max(ans, get(0, 0, n - 1, in[z], in[x]));
    re ans;
}

int getans(int x, int y) {
    int z = lca(x, y);
    re max(jump(x, z), jump(y, z));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(up, -1, sizeof(up));
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0);
    hld(0);
    cin >> m;
    while (m--) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'I') {
            upd(0, 0, n - 1, y, in[x - 1]);
        } else {
            x--;
            y--;
            cout << getans(x, y) << "\n";
        }
    }
}
