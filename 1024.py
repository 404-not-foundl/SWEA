test, fake = int(input())


for index in range(1, test+1):
    inventory = []

    for number in range(101):
        inventory.append(0)
    
    for many in range(1000):
        grade = int(input())
        inventory[grade] += 1
    
    maximum = int(max(inventory))
    maximum_number = 0
    
    for number in range(1, 101):
        if maximum == inventory[number]:
            maximum_number = number
    
    print(f"#{index} {maximum_number}")