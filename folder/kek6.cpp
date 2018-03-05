#define MOD 1000000007
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>

#define ret return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define tr(x, y) (x)*(x) + (y)*(y)
#define re(n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;
template<class T> T abs(T x) { ret x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { ret a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { ret a * a; }
template<class T> T sgn(T a) { ret a > 0 ? 1 : (a < 0 ? -1 : 0); }

int n, m, k, a ,b, c, z;
string s, ss[4000000], sc;
void f(){
    int buf = 0,i,j,k,q;
    // for(int i = n - 1; i > 0; i--){
    //     if()
    // }

     while (1) {   // nachinaem perebirat' vse vozmozhnuye perestanovki
//    printf("%s\n", sc);  // vuvod ocherednoy perestanovki
    ss[z] = sc;
    for (i = n-2; i >= 0  && sc[i] >= sc[i+1] ; i--);  // nahodim samoe pravoe mesto, gde s[i] < s[i+1]
      if (i<0) break; // uze poluchili vse perestanovki
    for(j=n-1; sc[i] >= sc[j]; j--) ; // nahodim s[j] - naimenshuy element spravo ot s[i] i bolshe ego
        // menyaem s[i] -  s[j]
    buf = sc[j];
   sc[j] = sc[i];
   sc[i] = buf;
 
   // obraschaem el-ntu spravo ot s[i]
   for ( k=i+1, q=n-1; k < q; k++ , q-- )
     {   buf=sc[k];
         sc[k]=sc[q];
         sc[q]=buf;
     }
 
  }
 
    z++;
}


int main(){
    // freopen("lewa.in","r",stdin);
    // freopen("tree.out", "w", stdout);
    // ios::sync_with_stdio(0);
	// cin.tie(0);
    // cout.tie(0);

   
    cin >> s;
    n = sz(s);
    string w = s;
    sc = "abc";
    // if(n < 10)ret cout << 0,0;

    f();
    re(10){
        cout << ss[i]<< " ";
    }

    
    
}