#define MOD 1000000007
#include <iostream>
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
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <time.h> 
#include <numeric>    
   
#define ret return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x)  ((int) (x).size())
#define len(x) ((int) (x).length())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define tr(x, y) (x)*(x) + (y)*(y)
#define ttr(x, y) (x)*(x) - (y)*(y)
#define pi (3.14159265358979323846264338327950288419716939937510)
#define re(n) for (int i = 0; i < (n); i++)
#define rej(n) for (int j = 0; j < (n); j++)
#define readInt(x) scanf("%d", &x);
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define readInts(x, n) for(int i=0; i<n; i++) scanf("%d", x + i);
#define writeInt(x) printf("%d\n", x);
  

  
using namespace std;
   
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
template<class T> T abs(T x) { ret x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { ret a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { ret gcd(a, b) ? (a / gcd(a, b) * b) : 0;}
template<class T> T sqr(T a) { ret a * a; }
template<class T> T sgn(T a) { ret a > 0 ? 1 : (a < 0 ? -1 : 0); }
   
vl f;
ll a,b,x,y,n,m,ans,cur,pr,sum;

vl v;
string s,text;

vi preff (string s) {
    int n = sz(s);
    vi ans(n);
    for(int i = 1 ; i < n;i++){
        int j = ans[i - 1];
        while(s[j] != s[i] && j) j = ans[j - 1];
        if(s[j] == s[i]) j++;
        ans[i] = j;
    }
    ret ans;
}
int main() {
    //  freopen("lewa.in","r",stdin);
    //  freopen("search.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> text >> s;
    string kek = s + "?" + text;
    n = sz(s);
    m = sz(text);

    vi v = preff(kek);
    vi vans;
    for(int i = n + 1 ;i < m + n + 1;i++){
        if(v[i] == n) vans.pb(i - 2 * n + 1);
    }
    cout << sz(vans) << endl;
    re(sz(vans))cout << vans[i] << " ";



}