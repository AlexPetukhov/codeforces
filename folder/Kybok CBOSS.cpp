#define MOD 1000000007
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
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

int n, m, k, b, c, ans, je;
int a[400000];
int ti[123];
int t[123][123];
vector<int> v;

void swap(int *a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}
bool NextSet(int *a, int n)
{
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false; 
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1;
    while (l<r)
        swap(a, l++, r--);
    return true;
}
int main(){
    // freopen("lewa.in","r",stdin);
    // freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    
    cin >> n >> k;
    re(n){
        rep(j,n){
            cin >> t[i][j];
        }
    }
    re(n)cin >> ti[i];
    
    re(n)a[i] = i + 1;
    
    re(k){
        v.pb(a[i]);
        if(i + 1 < k)ans += t[i][i+1];
        ans += ti[i];
        // cout << a[i] << " " ;
    }
    
    if(k < n){
        for(int i = k; i < n; i++){
            je = i;
            // cout << a[i] << " " ;
            c += t[i-1][i];
            if(i + 1 < k)c += t[i][i+1];
            c += ti[i];
            // cout << ans << " " << c  << " ";
            // cout << ans - t[i-k][i-k+1] - ti[i-k] << " ";
            if( t[i-k][i-k+1] + ti[i-k] > c){
                v.clear();
                for(int qa = je - k + 1; qa <= je; qa++){
                    v.pb(a[qa]);
                }
                ans -= t[i-k][i-k+1] + ti[i-k] - c;
            }
        }
        
    }

    
    // re(n)cout << a[i] << " ";
    
    while (NextSet(a, n))
    re(n){
        if(!i%n){
            for(int z = i; z < i + n; z++){
                // cout << a[z] << " ";
                int cc = 0;
                rep(l,k){
                    if(l + 1 < k)cc += t[a[l]-1][a[l + 1]-1];
                    cc += ti[a[l]-1];
                    
                }
                // cout << cc << " ";
                if(cc < ans){
                    v.clear();
                    for(int qa = 0; qa < k; qa++){
                        v.pb(a[qa]);
                    }
                    ans = cc;
                }

                if(k < n){
                    for(int qe = k; qe < n; qe++){
                        je = qe;
                        // cout << a[i] << " " ;
                        cc += t[qe - 1][qe];
                        if(qe + 1 < k)cc += t[qe][qe + 1];
                        cc += ti[qe];
                        // cout << ans << " " << c  << " ";
                        // cout << ans - t[i-k][i-k+1] - ti[i-k] << " ";
                        if( t[qe - k][qe - k + 1] + ti[qe - k] > cc){
                            v.clear();
                            for(int qa = je - k + 1; qa <= je; qa++){
                                v.pb(a[qa]);
                            }
                            ans -= t[qe - k][qe - k + 1] + ti[qe - k] - cc;
                        }
                    }
                }
            }
        }  
    }    


    // cout << endl;
    cout << ans << endl;
    for(auto i : v)cout << i << " ";

}