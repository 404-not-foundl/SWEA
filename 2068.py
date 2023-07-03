test = int(input())

for index in range(test):
    inventory = list(map(int, input().split()))
    inventory.sort()
    print("#"+str(index)+" "+str(inventory[-1]))
    
'''
T = int(input())
 
for t in range(1, T+1):
    numbers = list(map(int, input().split()))
     
    max_num = max(numbers)
     
    print(f"#{t} {max_num}")
'''