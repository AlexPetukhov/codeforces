#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define rep(i,n) for(int (i)=0;(i)<(n);++(i)) 
typedef long long ll;

using namespace std;

// int x=0;

int main(){
    int ans1=0,ans2=0;
    
    priority_queue<int, vector<int>, greater<int> > pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;
    priority_queue<int> pq3;
    priority_queue<int> pq4;

    string s;
    cin >> s;
    int len = s.length();
    int f[3];
    int sum1=0,sum2=0;
    int l[3];
    int x=0;
    rep(i,len){
        if(i<3){
            x = s[i] - '0';
            pq1.push(x);  
            pq3.push(x);
            sum1 +=x;
            // cout<< x;
        }
        if(i>=3){
            x = s[i] - '0';
            pq2.push(x);
            pq4.push(x);
            sum2+=x;
            // cout<< x;
    }
}

    int on=0;
    int kek=0;
    // cin >> kek;
    // cout<< kek <<endl;
    // cout<< "SUM " << sum1 <<endl << sum2 << endl;
    if(sum1 > sum2){
        rep(i,3){
            on = pq2.top();
            // cout<< on<<endl; // !!!
            pq2.pop();
            pq2.push(9);
            sum2 += (9-on);
            // cout << "NEWSUM"<<sum2<<endl;
            if(sum2 >= sum1){
                ans1=i+1;
                // cout << "ASD";
                goto label;
            }
        }
    }
    if(sum1 == sum2){
        cout << "0"<<endl;
        return 0;
    }
    if(sum1 < sum2){
        rep(i,3){
            on = pq1.top();
            // cout<< on<<endl; // !!!
            pq1.pop();
            pq1.push(9);
            sum1 += (9-on);
            if(sum1 >= sum2){
                ans1=i+1;
                // cout << "A1255SD";
                
            }
        }

    }

    //  REVERSE!!!
label :

    if(sum1 > sum2){
        rep(i,3){
            on = pq4.top();
            // cout<< on<<endl; // !!!
            pq4.pop();
            pq4.push(0);
            sum2 += (0-on);
            // cout << "NEWSUM"<<sum2<<endl;
            if(sum2 >= sum1){
                ans2=i+1;
                // cout << "656ASD";
                goto label1;
            }
        }
    }
    if(sum1 == sum2){
        cout << "0"<<endl;
        // cout << "AS7467D";
        return 0;
    }
    if(sum1 < sum2){
        rep(i,3){
            on = pq3.top();
            // cout<< on<<endl; // !!!
            pq3.pop();
            pq3.push(0);
            sum1 += (0-on);
            if(sum1 >= sum2){
                ans2=i+1;
                // cout << "A76587SD";
            }
        }

    }
    label1:
    int ans = min(ans1,ans2);

    cout << ans<<endl;
}