#include <iostream>
#include <vector>

using namespace std;

bool comparing(vector<int> list){
    bool compare[10] = {false};
    bool result = true;

    for(int i = 0; i < list.size(); i++){
        if(compare[list[i]] == false) compare[list[i]] = true;
        else{
            result = false;
            break;
        }
    }

    if(result) return true;
    else return false;
}

void sudoku(int count){
    int map[9][9], number;
    bool sudoku_puzzle = true;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> number;
            map[i][j] = number;
        }
    }

    for(int i = 0; i < 9; i++){
        vector<int> compare, compare_;
        for(int j = 0; j < 9; j++) compare.push_back(map[i][j]);
        sudoku_puzzle = comparing(compare);
        if(!sudoku_puzzle) break;
        for(int j = 0; j < 9; j++) compare_.push_back(map[j][i]);
        sudoku_puzzle = comparing(compare_);
        if(!sudoku_puzzle) break;
    }

    if(sudoku_puzzle){
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++){
                vector<int> compare;
                for(int c = 0; c < 3; c++){
                    for(int d = 0; d < 3; d++){
                        compare.push_back(map[c+3*a][d+3*b]);
                    }
                }
                sudoku_puzzle = comparing(compare);
                if(!sudoku_puzzle) break;
            }
            if(!sudoku_puzzle) break;
        }
    }

    if(sudoku_puzzle) cout << "#" << count << " " << 1 << endl;
    else cout << "#" << count << " " << 0 << endl;
}

int main(){
    int test;

    cin >> test;

    for(int i = 0; i < test; i++) sudoku(i+1);

    return 0;
}