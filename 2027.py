test = int(input())

for index in range(1, test+1):
    result = 0
    inventory = list(map(int, input().split()))
    
    for n in range(len(inventory)):
        if inventory[n] % 2:
            result += inventory[n]
    
    print(f"#{index} {result}")