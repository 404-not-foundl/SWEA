test = int(input())

for test_number in range(1, test+1):
    fake = input()
    Ai = list(map(int, input().split()))
    Bj = list(map(int, input().split()))
    inventory = []
    
    if len(Ai) >= len(Bj):
        A_Smaller = False
    else:
        A_Smaller = True

    if A_Smaller:
        for index in range(len(Bj) - len(Ai) + 1):
            add_up = 0
            for multi in range(index, index+len(Ai)):
                add_up += Bj[multi]*Ai[multi-index]
            inventory.append(add_up)
    else:
        for index in range(len(Ai) - len(Bj) + 1):
            add_up = 0
            for multi in range(index, index+len(Bj)):
                add_up += Bj[multi-index]*Ai[multi]
            inventory.append(add_up)
    
    result = max(inventory)
    
    print(f"#{test_number} {result}")