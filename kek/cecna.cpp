#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std; 

typedef vector<int> children_vector;

vector<children_vector> penis;

children_vector getChildren(int u) {
    // cout << "getChildren " << u << endl;
    return penis[u];
}

double getExpectation(int self, int prev) {
    children_vector children = getChildren(self);
    
    double expectation = 0.0;
    int size = 0;
    for(int i = 0; i<children.size(); i++) {
        int child = children[i];
        if (child != prev) {
            expectation += getExpectation(child, self) + 1;
            size++;
        }
    }
    
    // cout << "getExpectation " << self << " " << prev << " " << size << " " << expectation / size << endl;
    return size < 1 ? 0 : expectation / size;
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        penis.push_back( children_vector() );
    }

    for(int i = 0; i < n-1; i++){
        int u, v;

        cin >> u;
        cin >> v;
        penis[u-1].push_back(v-1);
        penis[v-1].push_back(u-1);
        // int min = u < v ? u : v;
        // int max = u > v ? u : v;
        // penis[min-1].push_back(max-1);
    }        

    // cout << getExpectation(0, -1) << endl;    
    printf("%.7lf\n", getExpectation(0, -1) );
}