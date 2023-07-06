#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string int_to_string(int number) {
	string letter;

	switch(number)
	{
	case 0:
		letter = "ZRO"; break;
	case 1:
		letter = "ONE"; break;
    case 2:
		letter = "TWO"; break;
    case 3:
		letter = "THR"; break;
    case 4:
		letter = "FOR"; break;
    case 5:
		letter = "FIV"; break;
    case 6:
		letter = "SIX"; break;
    case 7:
		letter = "SVN"; break;
    case 8:
		letter = "EGT"; break;
    case 9:
		letter = "NIN"; break;
	}

	return letter;
}

int string_to_int(string letter) {
	int number;

    if(letter == "ZRO"){
        number = 0;
    }else if(letter == "ONE"){
        number = 1;
    }else if(letter == "TWO"){
        number = 2;
    }else if(letter == "THR"){
        number = 3;
    }else if(letter == "FOR"){
        number = 4;
    }else if(letter == "FIV"){
        number = 5;
    }else if(letter == "SIX"){
        number = 6;
    }else if(letter == "SVN"){
        number = 7;
    }else if(letter == "EGT"){
        number = 8;
    }else if(letter == "NIN"){
        number = 9;
    }
    
	return number;
}

void GNS(int test) {
	int size;
	string fake, letter;
    vector<int> list;

	cin >> fake >> size;

    for(int i = 0; i < size; i++){
        cin >> letter;
        list.push_back(string_to_int(letter));
    }

    sort(list.begin(), list.end());

    cout << "#" << test <<endl;
    for(int i = 0; i < list.size(); i++) cout << int_to_string(list[i]) << " ";
    cout << endl;
}

int main() {
	int test;

	cin >> test;

	for (int i = 1; i < test + 1; i++) GNS(i);

	return 0;
}