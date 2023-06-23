import pandas as pd
from collections import defaultdict
# Outlook, Temperature, Humidity Windy, Play
weather = pd.read_table('weather.txt', sep=' ')

correct_list = []
wrong_list = []
for i, items in weather.iterrows():
    proba_yes = 1
    proba_no = 1
    for j, item in enumerate(items):
        no = 0
        yes = 0
        # itemが一致しているときの個数を数える
        for _, items2 in weather.iterrows():
            if items2[j] == item:
                if items2['Play'] == 'YES':
                    yes += 1
                elif items2['Play'] == 'NO':
                    no += 1
        # 確率を積にする
        proba_yes *= yes / (yes + no)
        proba_no *= no / (yes + no)

    # YESとNO、どちらが高いか判定
    judge = ''
    if proba_yes > proba_no:
        judge = 'YES'
    else:
        judge = 'NO'

    # YES/NOが正解かどうか
    if judge == items[-1]:
        correct_list.append(i)
    else:
        wrong_list.append(i)

# 正解したかどうか
print(f'correct : {correct_list}')
print(f'wrong   : {wrong_list}')

# 結果
# すべてcorrect_listの中に入っているので、分類に成功している