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

void fft(vector<pt> &a, bool invert) {
	int n = a.size();
	if (n == 1)return;
	vector<pt> a0(n / 2), a1(n / 2);
	for (int i = 0, j = 0; i < n; i += 2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i + 1];
	}
	fft(a0, invert), fft(a1, invert);
	double alp = 2 * M_PI / n * (invert ? -1 : 1);
	pt w(1), wn(cos(alp), sin(alp));
	FOR(n/2) {
		a[i] = a0[i] + w * a1[i];
		a[i+n/2] = a0[i] - w * a1[i];
		if (invert) a[i] /= 2, a[i + n / 2] /= 2;
		w *= wn;
	}
}

void multiply(const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<pt> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	FOR(n) fa[i] *= fb[i];
	fft(fa, true);

	res.resize(n);
	FOR(n) 
		res[i] = (int)(fa[i].real() + 0.5);
}

void Solve() {
	string s;
	getline(cin, s);
	VI a(s.length());
	FOR(s.length()) a[i] = s[i] - '0';
	VI b = a, res;
	multiply(a, b, res);
	int ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '1') ans += res[2 * i] /2;
	}
	cout << ans;
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