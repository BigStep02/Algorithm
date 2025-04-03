N = str(input())
F = int(input())

for i in range(0, 100):
    if len(str(i)) == 1:
        temp = N[0:len(N) - 2] + '0' + str(i)
        if int(temp) % F == 0:
            print('0' + str(i))
            break
    else:
        temp = N[0:len(N) - 2] + str(i)
        if int(temp) % F == 0:
            print(i)
            break