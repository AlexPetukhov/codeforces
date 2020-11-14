#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <regex>
#include <math.h>
#include <map>
#include <iterator>
#include <climits>
#include <numeric>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <array>
#include <valarray>
#include <complex>
#include <random>
#include <functional>


using namespace std;

#define int long long
#define ll long long
typedef int hv;
#define double long double
typedef complex<double> pt;
#define make(type, x) type x; cin>>x
#define make2(type, x, y) type x, y; cin>>x>>y
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z
#define make4(type, x, y, z, q) type x, y, z, q; cin>>x>>y>>z>>q
#define ALL(x) (x).begin(), (x).end()
#define FORIT(p) for(auto it = p.begin(); it != p.end(); it++)
#define FOR(b) for(signed i = 0; i <(b); i++)
#define FORE(i, l, r) for(int i = (l); i < (r); i++)
#define NFOR(i, n) for(int i = (((int) n)-1); i >= 0; i--)
#define VI vector<int>
#define VVI vector<vector<int>>
#define PII pair<int, int>
#define PPII pair<PII, int>
#define M7 1000000007l
#define M9 1000000009l
#define makev(a, n) VI a(n); FOR(n) cin >> a[i];
#define endl '\n'

const int md = 786433;
const int root = 1 << 18;
const int obrRoot = 786430;
const int root_pw = 1 << 16;

int fpow(int a, int b) {
	if (b == 0) return 1;
	if (b & 1) return (a*fpow(a, b-1)) % md;
	int q = fpow(a, b / 2);
	return (q * q) % md;
}

int getObr(int a) {
	return fpow(a, md - 2);
}

void fft(vector<int> & a, bool invert) {
	int n = a.size();

	for (int i = 1, j = 0; i<n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		int wlen = invert ? obrRoot : root;
		for (int i = len; i<root_pw; i <<= 1)
			wlen = wlen * 1ll * wlen % md;
		for (int i = 0; i<n; i += len) {
			int w = 1;
			for (int j = 0; j<len / 2; ++j) {
				int u = a[i + j], v = a[i + j + len / 2] * 1ll * w % md;
				a[i + j] = u + v < md ? u + v : u + v - md;
				a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + md;
				w = w * 1ll * wlen % md;
			}
		}
	}
	if (invert) {
		int nrev = getObr(n);
		for (int i = 0; i<n; ++i)
			a[i] = a[i] * 1ll * nrev % md;
	}
}

void multiply(const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	FOR(n) fa[i] = (fa[i]*  fb[i])%md;
	fft(fa, true);

	res.resize(n);
	FOR(n)
		res[i] = fa[i];
}

void Solve() {

	make2(int, n, h);
	VI a = { 1, 0 }, b{ 0,1 }, res;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < a.size(); ++j) {
			a[j] = (2 * a[j] + b[j]) % md;
		}
		multiply(a, b, res);
		a.resize(res.size());
		b.resize(res.size());
		a[0] = 0;
		for (int j = 0; j + 1 < a.size(); ++j) {
			a[j + 1] = res[j]%md;
		}
		swap(a, b);
	}
	if (n >= b.size()) cout << 0;
	else cout << b[n];
}



signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef _SUPER_DEFINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	Solve();
	while (!cin.eof()) {
		string s = "_";
		do getline(cin, s);
		while (!cin.eof() && !s.empty());
		if (cin.eof()) return 0;
		FOR(2) cout << endl;
		fflush(stdout);
		Solve();
	}
#else
	Solve();
#endif
	return 0;
}