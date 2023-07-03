def one_to_ten(checking):
    compare = [0, 0, 0, 0, 0, 0, 0, 0, 0]
    for index in len(checking):
        compare[checking[index]-1] += 1
    
    if min(compare):
        return False
    else:
        return True
    

test = int(input())

for t in range(test):
    inventory = []
    sudoku_test = True
    for n in range(9):
        numbers = list(map(int, input().split()))
        sudoku_test = one_to_ten(numbers)
        if not sudoku_test:
            break
        inventory.append(numbers)
    if not sudoku_test:
        print(f"#{t} 0")
    else:
        for n in range(9):
            sudoku_test = one_to_ten([inventory[0][n],inventory[1][n],inventory[2][n],inventory[3][n],inventory[4][n],inventory[5][n],inventory[6][n],inventory[7][n],inventory[8][n]])
            if not sudoku_test:
                break
        if not sudoku_test:
            print(f"#{t} 0")
        
    