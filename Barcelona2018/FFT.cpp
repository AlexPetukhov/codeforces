#include <bits/stdc++.h>
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
  
template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }
template <class T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }
  
#define filename ""
  
const D pi = acos(-1.);
const int N = 6e5 + 20;
const int inf = 1e9 + 100;
  
typedef complex<D> cd;
cd w[1 << 16];
cd f[1 << 16];
cd t[1 << 16];
cd c[1 << 16];
int bit[1 << 16];
  
int ans[1 << 16];
  
int rev(int x, int k) {
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans = ans * 2 + (x & 1);
        x >>= 1;
    }
    return ans;
}
  
void step(int k, cd* a, cd* b, int n, bool inv)
{
    int h = n >> 1;
    int m = n >> k;
    cd u, v, r = 1;
    int c = m;
    D ang = 2 * pi / (D) (1 << k);
    if (inv) ang = -ang;
    cd ww = cd(cos(ang), sin(ang));
    for (int i = 0; i < h; i++) {
        u = a[i << 1];
        v = r * a[(i << 1) | 1];
        b[i] = u + v;
        b[i + h] = u - v;
        if (!--c) {
            c = m;
            r *= ww;
        }
    }            
}
  
void fft(cd* a, int p, bool inv)
{
    for (int i = 0; i < (1 << p); i++) {
    	int x = rev(i, p);
        if (x > i) 
            swap(a[i], a[x]);
	}
    for (int i = 1; i <= p; i++) 
        if (i & 1) step(i, a, c, 1 << p, inv);
        else step(i, c, a, 1 << p, inv);
    if (p & 1)
        memcpy(a, c, (1 << p) * sizeof(c[0]));
    if (inv)
        for (int i = 0; i < (1 << p); i++)
            a[i] /= (D) (1 << p);
}
  
int main()
{
    string s, h;
    cin >> s >> h;
    reverse(all(s)), reverse(all(h));
    for (int i = 0; i < sz(s); i++) 
        f[i] = s[i] - '0';
    for (int i = 0; i < sz(h); i++)
        t[i] = h[i] - '0';
    int n = sz(s) + sz(h);
    while (n & (n - 1)) n++;
    int p = __builtin_ctz(n);
    fft(f, p, false);
    fft(t, p, false);
    for (int i = 0; i < n; i++)
        f[i] *= t[i];
    fft (f, p, true);
    for (int i = 0; i < n; i++)
        ans[i] = (int) (real(f[i]) + 0.5);
    for (int i = 0; i < n - 1; i++) {
        int x = ans[i];
        ans[i] = x % 10;
        ans[i + 1] += x / 10;
    }
    while (ans[n] == 0 && n > 0) n--;
    for (int i = n; i >= 0; i--)
        cout << ans[i];  
    re 0;
}