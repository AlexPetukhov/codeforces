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
 
 
#define M7 1000000007
#define pi 3.14159265359
 
#define int long long
#define re(x) for(int i = 0; i < (x); i++)
#define rej(x) for(int j = 0; j < (x); j++)
#define all(x) x.begin(), x.end()
#define makeunique(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define sz(x) (int)x.size()
#define pb push_back
#define ret return
#define fi first
#define se second
 
using namespace std;
 
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int> > vii;
typedef pair<int,int>  ii;
typedef long double dbl;
template<class T> T gcd(T a, T b) { ret a ? gcd (b % a, a) : b; }

 






int lp[10000000 + 1];
vector<int> pr;
 

void er(int N){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}


void solve(){
    int n;
    vi s;

    cin >> n;
    re(n){
        int x;
        cin >> x;
        s.pb(x);
    }

    vector<int> dp(100050, 1);
    for(int i = n - 1; i > 0; i--){
        int ind = i + 1;
        if(s[0] < s[i]) dp[0] = max(dp[0], dp[i] + 1);

        vi p;
        while(ind > 1){
            int d = lp[ind];
            p.pb(d);
            while(ind % d == 0) ind /= d;
        }
        for(auto o : p){
            int d = i + 1;
            while(d > 1){
                if(s[d - 1] < s[i]) dp[d - 1] = max(dp[d-1], dp[i] + 1);
                d /= o;
            }
        }
        // while(ind > 1){
        //     int d = lp[ind];
        //     if(s[d - 1] < s[i]){
        //         dp[d - 1] = max(dp[d - 1], dp[i] + 1);
        //     }
        //     ind /= d;
        // }
        cout << "index: " << i + 1 << "::";
        re(n) cout << i + 1 <<":" << dp[i] <<", ";
        cout << endl;
    }


    int ans = 0;
    re(n) ans = max(ans, dp[i]);
    cout << ans << endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("in.in", "r", stdin);
    //  freopen("position.out", "w", stdout);

    er(10000000);

    int t;
    cin >> t;
    re(t)solve();


    
    




}