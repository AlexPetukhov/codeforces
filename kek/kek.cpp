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
    int kek=0;
    ll n,k;
    char ch;
    string s;   
    int j=0;
    int max=0;
    int left;
    int vopros[26];
    int star[1];
    int arr[26];
    int numOfVopr=0;
    string s;
    cin >> s;
    int len = s.length();
    rep(i,s.length()){
        arr[ s[i] - 'a' ]++;
    }
    cin >> s;
    rep(i,s.length()){
        if(s[i] == '?'){
            numOfVopr++;
            vopros[j]=i;
            j++;
        }
        if(s[i] == '*'){
            star[0] = i;
        }

    }
    cin >> n;

    rep(i,n){
        cin >> s;

        rep(j,s.length()){
            if(s[j] == '?'){
                if(arr[s[j] - 'a'] > 0)
                else{}
            }
            if(arr[s[j] - 'a'] > 0 )return cout<<"YES",1;
            else{
                if( s[j] )
            }
        }

    }
    
    // cin >> s; 
    
    
    if(( n / k ) % 2 != 0 )cout<<"YES"<<endl;
    else  cout<< "NO" <<endl;



}

