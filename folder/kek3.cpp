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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long ll;
template<class T> T abs(T x) { ret x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { ret a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { ret a * a; }
template<class T> T sgn(T a) { ret a > 0 ? 1 : (a < 0 ? -1 : 0); }

const int N = 1e2 + 5;

int n, m, a, b;
int arr[354321],brr[354321];
double crr[5];
double d(double x, double y, int a, int b){
    ret sqrt( double((x - a))*double((x - a)) + double((y-b))*double((y-b)));
}
int main(){
    freopen("lewa.in","r",stdin);
    // freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    double x, y;
    int n1, n2, n3;
    double d1,d2,d3,c1,c2,c3;
    cin >> n;
    re(n){
        cin >> arr[i];
        cin >> brr[i];
        a += arr[i];
        b += brr[i];
    }
    x = double(a) / double(n);
    y = double(b) / double(n);
    cout << x << " "<< y<< endl;
    c1 = d(x,y,arr[0],brr[0]);
    c2 = d(x,y,arr[1],brr[1]);
    c3 = d(x,y,arr[2],brr[2]);

    if( c1 > c2 && c1 > c3){
        d1 = c1;
        n1 = 0;
        if(c2 > c3){
            d2 = c2;
            n2 = 1;
            d3 = c3;
            n3 = 2;
        }else {
            d2 = c3;
            n2 = 2;
            d3 = c2;
            d3 = 1;
        }
    }else {
        if(c2 > c1 && c2 > c3){
            d1 = c2;
            n1 = 1;
            if(c1 > c3){
                d2 = c1;
                n2 = 0;
                d3 = c3;
                n3 = 2;
            }else {
                d2 = c3;
                n2 = 2;
                d3 = c1;
                n3 = 0;
            }
        }
        else if(c3 > c1 && c3 > c2){
            d1 = c3;
            n1 = 2;
            if(c1 > c2){
                d2 = c1;
                n2 = 0;
                d3 = c2;
                c3 = 1;
            }else if(c2 > c1){
                d2 = c2;
                n2 = 1;
                d3 = c1;
                n3 = 0;
            }
        }
    }
    // sort(crr,crr+5,greater<int>());
    cout << d1 << " " << d2 << " " << d3 << endl;
    cout << n1 << " " << n2 << " "<< n3;

    // for(int i = 3; i < n; i++){
    //     double dq = d(x,y,arr[i],brr[i]
    //     if(dq > d3){
    //         if(dq > d2){
    //             if(dq > d1){
    //                 d3 = d2;
    //                 d2 = d1;
    //                 d1 = dq;
    //             }else {
    //                 d3 = d2;
    //                 d2 = dq;
    //             }
    //         }else d3 = dq;
    //     }
    // }





}