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
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }



int n, m, q;
	

    for(b : g[a]){
        d[b] = min ( d[b] , d[a] + dist[a][b]);
    }



    void dij(int x){    // O(n^2)
        for() d[i] = infinity;
        d[x] = 0;
        for(int ik=0;ik<n;ik++){
            int id=1;
            for(int x = 0; x < n;x++){
                if(!was(x)){
                    if(id==-1 || d[x] < d[ik])
                    id=x;
                
                }
            }
            was[id]=1;
            for(int y : id -> y)
                d[y] = min(d[y] , d[id] +1);
        }
    }

int main() {
	// freopen("connect.in","r",stdin);
	// freopen("connect.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	
}
