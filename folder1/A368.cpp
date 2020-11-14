#define M7 1000000007
#define M9 1000000009
#define MOD 998244353 
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
#define ren for (int i = 0; i < (n); i++)
#define rejn for (int j = 0; j < (n); j++)
#define read(x) scanf("%d", &x);
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define vpbx v.pb(x);
#define endl '\n'
#define int long long
  

  
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
template <char d = ' ', class T> ostream& operator << (ostream& out, vector<T>& v){ for(auto& e : v){ out << e << d; } return out; }
   

ll n,m,k,sum,ans,cur,pr;

int st[321][321];
int d[321][321];
int dx[4] = {1,0};
int dy[4] = {0,1};
// map<pii,pii> ma;
pii ma[321][321];
string f[321];
signed main() {
  // freopen("lewa.in","r",stdin);
  // freopen("ancestor.out", "w", stdout);
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


  cin >> n;
  re(n){
    string s;
    cin >> s;
    rej(n){
      int x = s[j] - '0';
      st[i][j] = x;
    }
  }
  re(n)rej(n)d[i][j]=-1;
  d[0][0] = 0;

  queue<pii> q;
  q.push({0,0});
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    int x = cur.fi;
    int y = cur.se;
    re(2){
      int x1 = x + dx[i];
      int y1 = y + dy[i];
      if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < n)
        if(d[x1][y1] == -1 || d[x1][y1] > d[x][y] + st[x1][y1]){
          d[x1][y1] = d[x][y] + st[x1][y1];
          ma[x1][y1] = {x,y};
          q.push({x1,y1});
        }
    }
  }
  re(n)rej(n)f[i][j]='.';
  f[0][0] = '#';
  
  int x = n-1;
  int y = n-1;
  f[x][y] = '#';
  while(1){
    int x1 = ma[x][y].fi;
    int y1 = ma[x][y].se;
    if(x1==0&&y1==0)break;
    f[x1][y1] = '#';
    x=x1;
    y=y1;
  }

  ren{
    rej(n){
      cout << f[i][j];
    }
    cout << endl;
  }


  // cout << endl;
  // ren{
  //   rejn{
  //     cout << d[i][j] << " ";
  //   }
  //   cout << endl;
  // }




}