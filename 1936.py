you = int(input())
opponent = int(input())
fact = True

if(you == 1):
    if(opponent == 2):
        print("B")
    else:
        print("A")
elif(you == 2):
    if(opponent == 3):
        print("B")
    else:
        print("A")
else:
    if(opponent == 1):
        print("B")
    else:
        print("A")
        
