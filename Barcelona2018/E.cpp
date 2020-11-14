#define MOD 786433
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
#define re(n) for (int i = 0; i < (n); i++)
#define rej(n) for (int j = 0; j < (n); j++)
#define readInt(x) scanf("%d", &x);
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define readInts(x, n) for(int i=0; i<n; i++) scanf("%d", x + i);
#define writeInt(x) printf("%d\n", x);
#define vpbx v.pb(x);
#define endl '\n'
  

  
using namespace std;
   
#define y1 asjgkhasgka
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
   

ll n,m,k,ans,sum,cur;

vvi g(100500);
int ar[100500];
void bfs(int n){
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto o : g[cur]){
            if(ar[o] == -1){
                q.push(o);
                ar[o] = ar[cur] + 1;
            }
        }
    }
}
int dsu[105000], ancestor[105000];
bool u[105000];
 
int dsu_get (int v) {
	return v == dsu[v] ? v : dsu[v] = dsu_get (dsu[v]);
}
 
void dsu_unite (int a, int b, int new_ancestor) {
	a = dsu_get (a),  b = dsu_get (b);
	if (rand() & 1)  swap (a, b);
	dsu[a] = b,  ancestor[b] = new_ancestor;
}
 
void dfs (int v) {
	dsu[v] = v,  ancestor[v] = v;
	u[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!u[g[v][i]]) {
			dfs (g[v][i]);
			dsu_unite (v, g[v][i], v);
		}
	for (size_t i=0; i<q[v].size(); ++i)
		if (u[q[v][i]]) {
			printf ("%d %d -> %d\n", v+1, q[v][i]+1,
				ancestor[ dsu_get(q[v][i]) ]+1);
}
 

int main() {
   freopen("lewa.in","r",stdin);
    //  freopen("search.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    re(n-1){
        int x,y;
        cin >> x>> y;
        x--;
        y--;
        g[x].pb(y);
    }
    re(n)ar[i]=-1;
    ar[0] = 0;
    bfs(0);
    re(n) cout<< ar[i] <<" ";
    
}