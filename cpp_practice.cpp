#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main(void){
    vector<int> list;

    for(int i = 0; i < 10; i++){
        list.push_back(i);
    }
    
    for(int i = 0; i < 10; i++){
        list.erase(list.begin());
    }
    
    for(int i = 0; i < list.size(); i++) cout << list[i] << " ";
    cout << endl;
    cout << list.empty() << endl;


    return 0;
}