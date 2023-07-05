#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

void print_vector(vector<int> list){
    for(int i = 0; i < list.size(); i++) cout << list[i] << " ";
    cout << endl;
}

int main(void){
    int ten = 10;
    vector<int> list;

    while(ten > 0){
        list.push_back(ten);

        ten--;
    }

    print_vector(list);

    return 0;
}