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
#include <functional>
#include <utility>
#include <stdlib.h>
#include <stdio.h>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define tr(x, y) (x)*(x) + (y)*(y)
using namespace std;
typedef long long ll;
int a[500100];
ll s[500100];

ll getSum(int l , int r ){
    ll ans = s[r];
    if(l)
        ans -= s[l - 1];
        
    re ans;
}

int main()
{
    // freopen("anagrams.in", "r", stdin);
    // freopen("anagrams.out", "w", stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    int n;
    int m;

    cin >> n;
    cin >> m;
    rep(i,n){

        cin >> a[i];

    }

    rep(i,n){
        s[i] = a[i] + (i ? s[i - 1] : 0);
    }

    rep(i,m){
        int l , r;
        cin >> l >> r;
        l--;
        r--;
        cout << getSum(l, r) << endl;

    }




}