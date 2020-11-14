//NNSU
#define M7 1000000007
#define M9 1000000009
#define MOD 998244353
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <regex>
#include <unordered_set>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <time.h>
#include <numeric>
#include <complex>
 
#define ret return
#define fi first
#define X first
#define Y second
#define se second
#define mp make_pair
#define pu push_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)  ((int) (x).size())
#define len(x) ((int) (x).length())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define tr(x, y) (x)*(x) + (y)*(y)
#define ttr(x, y) (x)*(x) - (y)*(y)
#define re(n) for (int i = 0; i < (n); i++)
#define rej(n) for (int j = 0; j < (n); j++)
#define ren for (int i = 0; i < (n); i++)
#define rejn for (int j = 0; j < (n); j++)
#define read(x) scanf("%d", &x);
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define vpbx v.pu(x);
#define endl '\n'
#define eb emplace_back
// #define int long long
#define pi 3.14159265358979
#define rpbx(n) for (int i = 0; i < (n); i++) {int x; cin >> x; v.push_back(x);}
 
 
using namespace std;
 
#define y1 asjgkhasgka
#define y0 aiohgasgas
#define next goas12gisas
#define left goas1232gisas
#define right goasgi315sas
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int, int> pii;
typedef vector <pii> vii;
typedef long long ll;
typedef vector<ll> vl;
typedef pair <ll, ll> pll;
typedef vector<double> vd;
typedef vector<vl> vvl;
typedef vector<pair<double,double> > vdd;
typedef vector<pll> vll;
typedef long double dbl;
template<class T> T abs(T x) { ret x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { ret a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { ret gcd(a, b) ? (a / gcd(a, b) * b) : 0;}
template<class T> T sqr(T a) { ret a * a; }
template<class T> T sgn(T a) { ret a > 0 ? 1 : (a < 0 ? -1 : 0); }
// template <char d = ' ', class T> ostream& operator << (ostream& out, vector<T>& v){ for(auto& e : v){ out << e << d; } return out; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) { os<<"{"; re(sz(t)- 1) {os<<t[i]<<",";} os<<t[sz(t)-1]; os<<"}"; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

 
const dbl EPS = 1e-9;
int n,k,cur,pr,m;
ll sum;
int ans;
int x,y;
 

signed main() {
  // freopen("lewa.in", "r", stdin);
  // freopen("output.out", "w", stdout);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    
  

}