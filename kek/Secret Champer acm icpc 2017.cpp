#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

vector<char> charVec[26];

int findLet(char ch, char toFind, string& usedChars) {
    // cout << "Find let " << ch << " " << toFind << endl;
    if (ch == toFind) return 1;

    usedChars.push_back(ch);
    auto children = charVec[ch];
    for(auto child : children) {
        // cout << "child of " << ch << " => " << child << ". toFind = " << toFind << endl;
        auto found = usedChars.find(child);
        if (found != string::npos) continue;

        auto result = findLet(child, toFind, usedChars);
        if (result == 1) {
            // usedChars.pop_back();
            return result;
        }
    }

    // usedChars.pop_back();
    return 0;
}


int checkWord(string s, string s1){
    if ( s.length() != s1.length() ) return 0;

    for(int i = 0; i<s.length(); i++) {
        // cout << i << " " << s[i] << " " << s1[i] << endl;

        if ( s[i] != s1[i] ) {
            // podbiraTb bykvi
            string usedChars;
            if(findLet(s[i] - 'a', s1[i] - 'a', usedChars) == 0) {
                return 0;
            }

        }
    }

    return 1; 
}



int main(){
    int n,m;
    cin >> m >> n;
    char ch,ch1;

    string  s[50];
    string s1[50];
    
    // map<char, vector<char> > tree;
    // a = 97
    for (int i = 0;i<m; i++) {
        cin >> ch;
        cin >> ch1;
        ch -= 'a';
        ch1 -= 'a';
        charVec[ch].push_back(ch1);
    }

    for(int i = 0; i < n; i++){
        cin >>  s[i];
        cin >> s1[i];
        if( checkWord(s[i] , s1[i]) == 1 ) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    // tree['d'].push_back('a');
    // tree['d'].push_back('b');
}
