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

int n, m, k;
int a[400000];
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

    int ans = 0;
    cin >> n >> k;
    m = n;

    if(!k)ret cout << 0,0;

    for (int i = 0; i < n; i++)a[i] = i + 1;

    // for (int i = 0; i < n; i++)cout << a[i] << " ";
    int fq = 0;
    while (NextSet(a, n))
    for (int i = 0; i < n; i++){
        // if(!i)continue;
        // if(!i%m)cout << endl;
    
        if(!i%m){
            fq = 0;
            // cout << a[i] << ":" << a[i+1] <<":" << a[i+2] << endl;
            for(int j = i; j< i + m-1; j++){
                if(abs(a[j] - a[j+1]) > k){
                    fq = 1;
                    // cout << endl << a[j] << " "<< a[j+1]<<endl;
                }
            }
            if(!fq)ans++;
        }

        
    }
    // cout << endl;
    cout << ans+1;
    
    

}