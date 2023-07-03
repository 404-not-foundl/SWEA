count = int(input())

inventory = list(map(int, input().split()))

inventory.sort()

print(inventory[int(count/2)])
