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
#define int long long
#define pi 3.14159265358979
#define rpbx(n) for (int i = 0; i < (n); i++) {int x; cin >> x; v.push_back(x);}
   
     
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
typedef long double dbl;
template<class T> T abs(T x) { ret x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { ret a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { ret gcd(a, b) ? (a / gcd(a, b) * b) : 0;}
template<class T> T sqr(T a) { ret a * a; }
template<class T> T sgn(T a) { ret a > 0 ? 1 : (a < 0 ? -1 : 0); }
template <char d = ' ', class T> ostream& operator << (ostream& out, vector<T>& v){ for(auto& e : v){ out << e << d; } return out; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) { os<<"{"; re(sz(t)- 1) {os<<t[i]<<",";} os<<t[sz(t)-1]; os<<"}"; return os;}
// template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}




const dbl EPS = 1e-9;
int n,m,k,cur,pr;
ll ans,sum;
vi v;
int a,b;

struct meet{
  int time;
  int dur;
  vs inv;
};
vector<meet> g;
bool comp(const meet & p1, const meet & p2){
  if(p1.time != p2.time)return p1.time < p2.time;
  return p1.dur < p2.dur;
}
void app(meet met){
  int f = 1;
  vs failed;
  re(sz(g)){
    rep(k,sz(met.inv)) 
      rej(sz(g[i].inv[j]))
        if(g[i].inv[j] == met.inv[k]){
          int s1 = met.time;
          int e1 = s1 + met.dur;
          int s2 = g[i].time;
          int e2 = s2 + g[i].dur;
          if(!(e1 <= s2 || s1 >= e2)){
            // intersecs
            f = 0;
            string name = met.inv[k];
            int q = 0;
            rep(z,sz(failed))
              if(failed[z] == name){
                q = 1;
                break;
              }
            if(!q)failed.pb(name);
          }
        }
  }
  if(f){
    cout <<"OK"<<endl;
    g.pb(met);
  }
  else{
    cout << "FAIL" << endl;
    re(sz(failed)) cout << failed[i] << " ";
    cout << endl;
  }
}
void prin(int day, string name){
  sort(all(g),comp);
  re(sz(g)){
    if(g[i].time / (24 * 60) == day){
      int f = 0;
      rej(sz(g[i].inv))if(g[i].inv[j] == name){
        f = 1;
        break;
      }
      if(f){
        int h = (g[i].time % (24 * 60)) / 60;
        int m = (g[i].time % (24 * 60)) % 60;
        int dur = g[i].dur;
        cout << h << ":";
        if(m < 10)cout << '0' <<m;
        else cout << m;
        cout << " " << dur << " ";
        rej(sz(g[i].inv))cout << g[i].inv[j] << " ";
        cout << endl;
      }
    }
  }
}
signed main() {
  freopen("lewa.in","r",stdin);
  // freopen("choose.out", "w", stdout);
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  cin >> n;
  
  re(n){
    string s;
    cin >> s;
    if(s[0] == 'A'){
      int day;
      string time;
      int dur;
      int k;
      cin >> day >> time >> dur >> k;
      int h = (time[0] - '0') * 10 + (time[1] - '0');
      int m = (time[3] - '0') * 10 + (time[4] - '0');
      int tim = day * 24 * 60 + h * 60 + m;
      vs in;
      rej(k){
        string s;
        cin >> s;
        in.pb(s);
      }
      meet met;
      met.dur = dur;
      met.time = tim;
      met.inv = in;
      app(met);
    }else {
      int day;
      string name;
      cin >> day >> name;
      prin(day,name);
    }
  }




}