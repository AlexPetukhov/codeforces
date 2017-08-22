#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int x=0;

int main(){
    
    int f1,f2=0;
    int n;
    int turn;
    int num;
    int newsum;
    int iprev;
    cin >> n;
    vector<int> vec;
    int sum=0;
    int numchet=0;
    int numnechet=0;
    for(int i =0;i<n;i++){

        cin >> num;
        sum+= num;
        vec.push_back(num);
        if(num % 2 == 0 ){
            f2=1;
            numchet++;
        }
        if(num % 2 != 0 ){
            f1=1;
            numnechet++;
        }
        
    }
    cout<< sum;  
    // cin >> x;
    if(sum % 2 != 0 )cout<< "First"<<endl;
    else{
        if(f1 == 0 ) cout<<"Second"<<endl;
        else{
             newsum=0;
             turn=1;
             iprev=0;
            while(vec.size() != 0){

            
                newsum=0;
                iprev=0;
                if(turn == 1){
                    for(int i=0;i<vec.size();i++){

                        if(numchet  == 1){
                            i++;
                        }
                        newsum+=vec[i];

                        if(newsum % 2 != 0){
                            iprev = i;

                        }
                }
                    vec.erase(vec.begin(),vec.begin()+iprev);
                    // i=0;
                    turn = 0;

                }
                if(turn == 0 ){
                    for(int i=0;i<vec.size();i++){

                        if(numnechet  == 1){
                            i++;
                        }
                        newsum+=vec[i];

                        if(newsum %2 == 0){
                            iprev = i;
                        }
                }
                    if(numnechet  == 1){
                        vec.erase(vec.begin()+1,vec.begin()+iprev);
                    }
                    if(numnechet  != 1){
                        vec.erase(vec.begin(),vec.begin()+iprev);
                    }
                    // i=0;
                    turn = 1;
                    
                }
            }

            
            if(turn == 0){
                cout<< "First"<<endl;
            }
            if(turn == 1){
                cout<< "Second"<<endl;
            }
    }


    }


}
