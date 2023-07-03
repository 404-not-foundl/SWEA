number = int(input())
result = 0
taken_out = 0

while not number == 0:
    taken_out = number % 10
    result += taken_out
    number -= taken_out
    number /= 10

print(int(result))