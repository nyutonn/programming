dp = []
x = 'curious'
y = 'buibui'
for i in range(len(x) + 1):
    dp.append([0]*(len(y) + 1))
    for j in range(len(y) + 1):
        if i != 0 and j != 0:
            dp[i][j] = min(dp[i-1][j] + 1,
                           dp[i][j-1] + 1,
                           dp[i-1][j-1] + (0 if x[i-1] == y[j-1] else 1))
        elif i == 0:
            dp[0][j] = j
        elif j == 0:
            dp[i][0] = i

from pprint import pprint
pprint(dp)
print(f"編集距離: {dp[-1][-1]}")