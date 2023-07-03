#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int count, number;
    vector<int> list;
    cin >> count;

    for(int i = 0; i < count; i++){
        cin >> number;
        list.push_back(number);
    }

    sort(list.begin(), list.end());

    count /= 2;

    cout << list[++count] << endl;

    return 0;
}