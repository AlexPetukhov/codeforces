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

vi ar,br;


ll msa[2123], bsa[2123];
int main() {
//    freopen("lewa.in","r",stdin);
    //  freopen("search.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >>m;
    re(n){
        int x;
        cin  >> x;
        ar.pb(x);
    }
    re(m){
        int x;
        cin >> x;
        br.pb(x);
    }
    ll x;
    cin >> x;
    for(int j = 1; j <= n;j++){
        ll cur = 0;
        re(j)cur += ar[i];
        msa[j] = cur;
        for(int i = j; i < n;i++){
            cur -= ar[i - j];
            cur += ar[i];
            msa[j] = min(cur,msa[j]);
        }
    }    
    for(int j = 1; j <= m;j++){
        ll cur = 0;
        re(j)cur += br[i];
        bsa[j] = cur;
        for(int i = j; i < m;i++){
            cur -= br[i - j];
            cur += br[i];
            bsa[j] = min(cur,bsa[j]);
        }
    }   

    for(int i = 1;i<=n;i++){
        for(int j = 1 ;j <= m;j++){
            if(bsa[j] * msa[i] <= x){
                ans = max(ans,(ll)i * j);
            }
        }
    }
    cout << ans << endl;

}   