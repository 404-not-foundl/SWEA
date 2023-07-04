#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main(void){
    int test, number_1, number_2, n, m;
    
    cin >> test;

    for(int t = 0; t < test; t++){
        vector<vector<int>> result;
        vector<pair<int, bool>> people;
        vector<pair<int, int>> order_list;
        pair<int, int> order;
        int current;
        queue<int> kids;
        queue<pair<int, int>> ordering;

        cin >> n >> m;
        
        for(int i = 0; i < n; i++){
            pair<int, bool> person = make_pair(i+1, false);
            people.push_back(person);
        }

        for(int i = 0; i < m; i++){
            cin >> number_1 >> number_2;
            order = make_pair(number_1, number_2);
            order_list.push_back(order);
        }

        while(!order_list.empty()){
            if(order_list.size() == m){
                current = order_list[0].first;
                ordering.push(order_list[0]);
                order_list.erase(order_list.begin());
            }
        }


    }




    return 0;
}