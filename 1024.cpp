#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void grade(){
    int test_number, number, max = 0, maximum_number;
    int list[101] = {0};

    cin >> test_number;

    for(int i = 0; i < 1000; i++){
        cin >> number;
        list[number]++;
    }

    for(int i = 1; i <= 100; i++){
        if(list[i] >= max){
            maximum_number = i;
            max = list[i];
        }
    }

    cout << "#" << test_number << " " << maximum_number << endl;
}

int main(){
    int test, number, fake;

    cin >> test;

    for(int i = 0; i < test; i++) grade();

    return 0;
}