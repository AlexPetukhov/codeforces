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

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define tr(x, y) (x)*(x) + (y)*(y)

using namespace std;

typedef long long ll;

int a[112345];
ll s[112345];
int main(){
    // freopen("lewa.txt","r",stdin);
    // freopen("anagrams.out", "w", stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    int ans = 0;
    int n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        s[i] = a[i] + (i ? s[i-1] : 0);
    }
    int sum = s[n-1]/3;
    int kek = 0;
    for(int i = 1;i<n-1;i++){
        if(s[i] == sum * 2){
            ans+=kek;
        }
        if(s[i] == sum)kek++;
        
    }
    cout << ans;

    return 0 ;

}