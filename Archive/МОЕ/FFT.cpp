const double pi = acos(-1.);
const int N = 6e5 + 20;
const int inf = 1e9 + 100;
  
typedef complex<double> cd;
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
    double ang = 2 * pi / (double) (1 << k);
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
            a[i] /= (double) (1 << p);
}
  
int main()
{
    string s, h;
    cin >> s >> h;
    reverse((s).begin(), (s).end()), reverse((h).begin(), (h).end());
    for (int i = 0; i < (int)s.size(); i++) 
        f[i] = s[i] - '0';
    for (int i = 0; i < (int)h.size(); i++)
        t[i] = h[i] - '0';
    int n = (int)s.size() + (int)h.size();
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

    return 0;
}