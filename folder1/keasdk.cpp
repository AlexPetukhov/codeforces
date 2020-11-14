#define M7 1000000007
#define M9 1000000009
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
#define ren for (int i = 0; i < (n); i++)
#define rej(n) for (int j = 0; j < (n); j++)
#define read(x) scanf("%d", &x);
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define vpbx v.pb(x);
#define endl '\n'
// #define int long long
  

  
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
   


ll n,m,k,ans,cur,sum,pr;
int R,L,U,D;
int DR,DL,DU,DD;
int CR,CL,CU,CD;
int TR,TL,TU,TD;
string s;
ll go(){
    ll ans = 1e15;
    int cr=0,cl=0,cu=0,cd=0;
    int j = 0;
    for(int i = 0; i < sz(s);i++){
        char c = s[i];
        int f = 0;
        if (c == 'U') {
            cu++;
        }
        else if (c == 'D') {
            cd++;
        }
        else if (c == 'L'){
            cl++;
        }
        else if (c == 'R'){
            cr++;
        }
        while(1){
            // if(j > i)break;
            char q = s[j];
            int f = 0;
            if (q == 'U') {
                if(cu -1 >= TU){
                    j++;
                    f=1;
                    cu--;
                }
            }
            else if (q == 'D') {
                if(cd - 1 >= TD){
                    j++;
                    f=1;
                    cd--;
                }
            }
            else if (q == 'L'){
                if(cl - 1 >= TL){
                    j++;
                    cl--;
                    f=1;
                }
            }
            else if (q == 'R'){
                if(cr - 1 >= TR){
                    j++;
                    f=1;
                    cr--;
                }
            }
            if(!f)break;
        }
        

        if(cu >= TU && cl >= TL && cr >= TR && cd >= TD){
            ans = min(ans,(ll)i-j+1);
            // cout << i <<":"<<j<<endl;
        }

    }
    ret ans;
}
signed main() {
    freopen("lewa.in","r",stdin);
    // freopen("ancestor.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int cx = 0, cy = 0;

    int n, x, y;

    cin >> n;
    cin >> s;
    cin >> x >> y;
    if(abs(x) + abs(y) > n)ret cout << -1,0;

    for (auto c : s)
    {
        if (c == 'U')
        {
            cy += 1;
            CU++;
        }
        else if (c == 'D')
        {
            cy += -1;
            CD++;
        }
        else if (c == 'L')
        {
            cx += -1;
            CL++;
        }
        else if (c == 'R')
        {
            cx += 1;
            CR++;
        }
    }
    if(x>0)R=x;
    else L=-x;
    if(y>0)U=y;
    else D=-y;



    if((abs(cx)+abs(cy))%2 != (abs(x)+abs(y))%2)ret cout <<-1,0;

    int dx = cx - x;
    int dy = cy - y;
    DR = CR - R;
    DL = CL - L;
    DU = CU - U;
    DD = CD - D;
    // cout << DR << " " << DL << " " << DU << " " << DD << endl;
    if(DR < 0)TR = -DR,DR=0;
    if(DL < 0)TL = -DL,DL = 0;
    if(DU < 0)TU = -DU,DU =0;
    if(DD < 0)TD = -DD,DD=0;
    // DR = max(0,DR);
    // DL = max(0,DL);
    // DU = max(0,DU);
    // DD = max(0,DD);

    cout << DR << " " << DL << " " << DU << " " <<DD << endl;
    cout << TR << " " << TL << " " << TU << " " << TD << endl;
    int q = min(DL,DR);
    DL -= q;
    DR -=q;
    q = min(DU,DD);
    DU -= q;
    DD -= q;
    if(DU % 2){
        if(TR % 2){
            DU--;
            TR--;
        }else if(TL % 2){
            DU--;
            TL--;
        }
    }else if(DD % 2){
        if(TR % 2){
            DD--;
            TR--;
        }else if(TL % 2){
            TL--;
            DD--;
        }
    }else if(DR % 2){
        if(TU % 2){
            TU--;
            DR--;
        }else if(TD% 2){
            TD--;
            DR--;
        }
    }else if(DL % 2){
        if(TU%2){
            TU--;
            DL--;
        }else if(TD%2){
            TD--;
            DL--;
        }
    }
    cout << DR << " " << DL << " " << DU << " " <<DD << endl;
    cout << TR << " " << TL << " " << TU << " " << TD << endl;

    if(DR > 0){
        TR += DR/2;
    } else if(DL > 0){
        TL += DL/2;
    }
    if(DU > 0){
        int dr = R - CR;
        int dl = L - CL;
        int dd = D - CD;
        if(dr > 0)
        TU += DU/2;
        
    } else if(DD > 0){
        TD += DD/2;
    }

    cout << DR << " " << DL << " " << DU << " " <<DD << endl;
    cout << TR << " " << TL << " " << TU << " " << TD << endl;
    ans = go();
    if(ans == 1)ans=0;
    assert(ans!=1000000000000000);
    cout << ans << endl;

    ret 0;
    // cout << cx <<":"<<cy << endl;
    // cout << dx <<":"<<dy << endl;

    if(x%2 != cx%2){

    }else{
        if(dx > 0){
            // need L
            L = dx/2;
        }else{
            // need R
            R = -dx/2;
        }
        if(dy > 0){
            //need D
            D = dy/2;
        }else{
            U = -dy/2;


        }
        cout << go();
        ret 0;
    }



}