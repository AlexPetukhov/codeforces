#include <bits/stdc++.h>
using namespace std;

// Kuhn's Algorithm (Maximum Matching)
// Time Complexity: O(|V| * |E|)

const int MAXN = 512;

vector<int> g[MAXN];	// Vertices from A numbered 0 to n - 1
int match[MAXN];		// Vertices from B numbered 0 to m - 1
int invmatch[MAXN];
bool vis[MAXN];

bool link[MAXN];
bool isValid[MAXN];

bool dfs(int u) {
	if (vis[u]) return false;
	vis[u] = true;

	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (match[v] == -1) {
			match[v] = u;
			invmatch[u] = v;
			return true;
		}
	}

	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (dfs(match[v])) {
			match[v] = u;
			invmatch[u] = v;
			return true;
		}
	}

	return false;
}

int kuhn(int n) {
	memset(match, -1, sizeof match);
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		memset(vis, false, sizeof vis);
		if (dfs(i)) {
			link[i] = true;
			isValid[i] = true;
			ans++;
		}
	}

	return ans;
}

void re (int n, int x) {
	link[x] = false;
	match[invmatch[x]] = -1;

	memset (vis, false, sizeof vis);
	for (int i = 0; i < n; ++i) {
		if (link[i]) continue;
		if (i == x) continue;

		if (dfs (i)) {
			link[i] = true;
			isValid[x] = false;
			return;
		}
	}

	link[x] = true;
	dfs (x);

	return;
}

int main () {

	int n, m;
	cin >> n >> m;

	string s;

	getchar();
	for (int i = 0; i < n; ++i) {
		getline (cin, s);
		int num = 0;
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == ' ') {
				g[i].push_back (num - 1);
				num = 0;
			} else {
				num *= 10;
				num += s[j] - '0';
			}
		}

		g[i].push_back (num - 1);
	}

	kuhn (n);
	for (int i = 0; i < n; ++i) {
		if (isValid[i]) {
			re (n, i);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (isValid[i])
			printf ("%d ", i + 1);
	}

	cout << endl;

	return 0;
}