#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std; 
int x=0;
int mins(string n){
    
        int len = n.length();
        char ch;
        int numb=0;
        int arr[1000];
        for(int i=0;i<len;i++){
    
            ch = n[i];
            numb = ch - '0';
            arr[i] = numb;
        }
    
        int elem = *min_element(arr,arr+len);
        x = distance(arr, find(arr, arr + len, elem)); 
        return elem;
    
    }


int sum(string n){

    char st;
    int numb= 0;
    int sum =0;
    for(int i =0;i<n.length();i++){
        char st = n[i];
        numb = st - '0';
    
        sum += numb;
    }
        return sum;
}



int main(){
 
    int a[4];
    int ans=0;
    int s;
    string n;
    int k;
    int len = n.length();
    cin >> k >> n;
    string newstr = n;
    if(sum(n) >= k) cout << "0"<< endl;
    else {
        int len = newstr.length();
        // cout<< "ASGAS"<<endl;
        for(int j = 1;j<=len;j++){

            
            int elem = mins(n);
            n[x] = '9';
            // cout<< x<<endl;
            // cout << elem<<endl;
            // cout << len << endl;
            
            // for(int z = 0;z < len;z++){
            //     int currn =  (n[z] -'0'); 
            //     // cout<< currn <<endl;
            //     if(currn == elem) {
            //         n[z] = '9';
            //         // cout<<"Z " << z<<endl;
            //         break;
            //         // cout<<n[z]<<endl;
            //     }
            // }
        // n[len-j] = '9';
            //  cout<<"SUM "<< sum(n)<<endl;
            // cout<<n<<endl;
            // cout<<sum(n)<<endl;
        if(sum(n) >= k){

            cout << j << endl;
            break;
        }

        }
    }



    

    // cout << sum("12345");
    

}
