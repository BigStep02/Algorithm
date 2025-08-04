import sys
input = sys.stdin.readline

N = int(input())

firstTeamScore = 0
secondTeamScore = 0
firstTeamWinTime = [0, 0]
secondTeamWinTime = [0, 0]
firstTeamLastGoal = [0, 0]
secondTeamLastGoal = [0, 0]

for i in range(N):
    goal = list(map(str, input().split()))
    if goal[0] == '1':
        if firstTeamScore <= secondTeamScore:
            firstTeamLastGoal = goal[1].split(':')
        firstTeamScore += 1
        if firstTeamScore == secondTeamScore:
            secondTeamWinTime[0] += int(firstTeamLastGoal[0]) - int(secondTeamLastGoal[0])
            secondTeamWinTime[1] += int(firstTeamLastGoal[1]) - int(secondTeamLastGoal[1])
    else:
        if secondTeamScore <= firstTeamScore:
            secondTeamLastGoal = goal[1].split(':')
        secondTeamScore += 1
        if firstTeamScore == secondTeamScore:
            firstTeamWinTime[0] += int(secondTeamLastGoal[0]) - int(firstTeamLastGoal[0])
            firstTeamWinTime[1] += int(secondTeamLastGoal[1]) - int(firstTeamLastGoal[1])

if firstTeamScore > secondTeamScore:
    firstTeamWinTime[0] += 48 - int(firstTeamLastGoal[0])
    firstTeamWinTime[1] += 0 - int(firstTeamLastGoal[1])

if firstTeamScore < secondTeamScore:
    secondTeamWinTime[0] += 48 - int(secondTeamLastGoal[0])
    secondTeamWinTime[1] += 0 - int(secondTeamLastGoal[1])

if firstTeamWinTime[1] >= 60:
    firstTeamWinTime[0] += firstTeamWinTime[1] // 60
    firstTeamWinTime[1] = firstTeamWinTime[1] % 60

if secondTeamWinTime[1] >= 60:
    secondTeamWinTime[0] += secondTeamWinTime[1] // 60
    secondTeamWinTime[1] = secondTeamWinTime[1] % 60

if firstTeamWinTime[1] < 0:
    change = abs(firstTeamWinTime[1]) // 60 + 1
    firstTeamWinTime[0] -= change
    firstTeamWinTime[1] = 60 * change + firstTeamWinTime[1]

if secondTeamWinTime[1] < 0:
    change = abs(secondTeamWinTime[1]) // 60 + 1
    secondTeamWinTime[0] -= change
    secondTeamWinTime[1] = 60 * change + secondTeamWinTime[1]

if len(str(firstTeamWinTime[0])) == 1 : firstTeamWinTime[0] = '0' + str(firstTeamWinTime[0])
if len(str(firstTeamWinTime[1])) == 1 : firstTeamWinTime[1] = '0' + str(firstTeamWinTime[1])
if len(str(secondTeamWinTime[0])) == 1 : secondTeamWinTime[0] = '0' + str(secondTeamWinTime[0])
if len(str(secondTeamWinTime[1])) == 1 : secondTeamWinTime[1] = '0' + str(secondTeamWinTime[1])

print(f'{firstTeamWinTime[0]}:{firstTeamWinTime[1]}')
print(f'{secondTeamWinTime[0]}:{secondTeamWinTime[1]}')