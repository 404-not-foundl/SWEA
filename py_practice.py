print("<시작>끝말잇기를 하자. 내가 먼저 말할게. 기차")
computer = "기차"
you = ""
finish = False
computer_inventory = list(map(str, "게맛살, 구멍, 글라이더, 기차, 대롱, 더치페이, 롱다리, 리본, 멍게, 박쥐, 본네트, 빨대, 살구, 양심, 이빨, 이자, 자율, 주기, 쥐구멍, 차박, 트라이앵글".split(", ")))

while not finish:
    you = input()
    if computer[len(computer)-1] != you[0]:
        print("글자가 안 이어져. 내가 이겼다!<끝>")
        finish = True
    else:
        for word in computer_inventory:
            if word[0] == you[len(you)-1]:
                computer = word
                print(computer)
                break
        else:
            print("모르겠다. 내가 졌어.<끝>")
            finish = True