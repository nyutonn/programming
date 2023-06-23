# データクラスの定義
class TitanicData():
    def __init__(self, pclass, age, sibsp, parch, fare, sex) -> None:
        self.pclass = float(pclass)
        self.age = float(age)
        self.sibsp = float(sibsp)
        self.parch = float(parch)
        self.fare = float(fare)
        self.sex = float(sex)
    
    def __str__(self) -> None:
        return f'pclass:{self.pclass}, age:{self.age}, sibsp:{self.sibsp}, parch:{self.parch}, fare:{self.fare}, sex:{self.sex}'

# データの格納
titanic_data = []
titanic_target = []
with open('titanic_test.csv') as f:
    for line in f:
        line = line.rstrip()
        if line[0] == '"':
            continue
        pclass, age, sibsp, parch, fare, sex, survived = line.split(',')
        td = TitanicData(pclass, age, sibsp, parch, fare, sex)
        titanic_data.append(td)
        titanic_target.append(int(survived))

# グラフの表示
from typing import Any
import matplotlib.pyplot as plt

x0 = [t.age for t in titanic_data if titanic_target[titanic_data.index(t)] == 0]
y0 = [t.fare for t in titanic_data if titanic_target[titanic_data.index(t)] == 0]
x1 = [t.age for t in titanic_data if titanic_target[titanic_data.index(t)] == 1]
y1 = [t.fare for t in titanic_data if titanic_target[titanic_data.index(t)] == 1]

plt.scatter(x0, y0, c='r')
plt.scatter(x1, y1, c='b')
# plt.show()

# 訓練データと正解データに分ける
import random
n_sum = len(titanic_data)
n_train = int(len(titanic_data) * 2 / 3)
n_test = n_sum - n_train
train_index = random.sample(range(n_sum), n_train)
train_index.sort()
train_target = []
train_data = []
test_target = []
test_data = []

# 各入力を正規化するための初期値
t_max = TitanicData('0', '0', '0', '0', '0', '0')
for data, target in zip(titanic_data, titanic_target):
     # 正規化するためにmaxを求める
    t_max.pclass += data.pclass
    t_max.age += data.age
    t_max.sibsp += data.sibsp
    t_max.parch += data.parch
    t_max.fare += data.fare
    t_max.sex += data.sex

# 訓練データとテストデータに分ける
for i, data in enumerate(titanic_data):
    target = titanic_target[i]
    # データを正規化する
    data.pclass /= t_max.pclass
    data.age /= t_max.age
    data.sibsp /= t_max.sibsp
    data.parch /= t_max.parch
    data.fare /= t_max.fare
    data.sex /= t_max.sex
    # 訓練データとテストデータに分ける
    if i in train_index:
        train_target.append(target)
        train_data.append(data)
    else:
        test_target.append(target)
        test_data.append(data)

# k近傍法から正解率を出す
import math
import numpy as np
def knn(k):
    ans_target = []
    # テストデータを取り出す
    for data, target in zip(test_data, test_target):
        # 訓練データの中から近いやつをk個選ぶ
        distances = [] # 距離を一旦リストに入れる
        for op_data, op_target in zip(train_data, train_target):
            distance = math.sqrt((op_data.pclass - data.pclass)**2 
                                + (op_data.age - data.age)**2
                                +(op_data.sibsp - data.sibsp)**2
                                    +(op_data.parch - data.parch)**2
                                    +(op_data.fare - data.fare)**2
                                        +(op_data.sex - data.sex)**2)
            distances.append(distance)
        # 距離が近い順にソートする
        sorted_distances = sorted(distances)
        # k個の近いやつを取り出す
        k_data = []
        for i in range(k):
            k_data.append(train_target[distances.index(sorted_distances[i])])
        # k個の近いやつの多数決を取る
        count = 0
        for i in k_data:
            if i == 1:
                count += 1
        if count >= k / 2:
            # print('生存')
            ans_target.append(1)
        else:
            # print('死亡')
            ans_target.append(0)

    # 正解率を出す
    accuracy = 0
    for i in range(n_test):
        if ans_target[i] == test_target[i]:
            accuracy += 1
    accuracy /= n_test
    # 正解率を返す
    return accuracy

# k近傍法の最適なkを発見する
max_k = 0
max_accuracy = 0
# print('k近傍法')
# for k in range(1, 21):
#     tmp_ave = 0
#     # 10回の平均を取る
#     for _ in range(10):
#         tmp_ave += knn(k)
#     tmp_ave /= 10
#     if tmp_ave > max_accuracy:
#         max_k = k
#         max_accuracy = tmp_ave
#     print(f'k : {k}, accuracy : {tmp_ave}')
# print(f'max_accuracy\nk : {max_k}, accuracy : {max_accuracy}')

# 8割から9割くらいの正解率が出たのでランダムよりもちょっといい感じになった！
# ランダムだと6割くらいだったはず

# パーセプトロンでもやってみる
# 内積の計算
def naiseki(w, x) -> float:
    ans = 0
    ans += w.pclass * x.pclass
    ans += w.age * x.age
    ans += w.sibsp * x.sibsp
    ans += w.parch * x.parch
    ans += w.fare * x.fare
    ans += w.sex * w.sex
    return ans

def perceptron(learning_rate):
    # 重みベクトルを学習させる
    w = TitanicData('0', '0', '0', '0', '0', '0') # 重みベクトル
    # 100回学習させる
    for _ in range(20):
        cnt = 0
        index = 0
        # 訓練データをランダムに並び替える
        train_index = random.sample(range(n_train), n_train)
        # 訓練データを使って重みベクトルを更新する
        for i in train_index:
            data = train_data[i]
            target = train_target[i]
            # print(index)
            index += 1
            # 内積の正負を見て重みベクトルを更新する
            if naiseki(w, data) >= 0:
                ans = 1
            else:
                ans = 0
            # 正解と違う場合は重みベクトルを更新する
            if ans != target:
                # print((target - ans) * data.pclass)
                cnt += 1
                w.pclass += (target - ans) * data.pclass * learning_rate
                w.age += (target - ans) * data.age * learning_rate
                w.sibsp += (target - ans) * data.sibsp * learning_rate
                w.parch += (target - ans) * data.parch * learning_rate
                w.fare += (target - ans) * data.fare * learning_rate
                w.sex += (target - ans) * data.sex * learning_rate
        # print(cnt)
    # テストデータを使って予想する
    ans_target = []
    for data in test_data:
        # 内積の正負を見て答えを出す
        if naiseki(w, data) >= 0:
            ans = 1
        else:
            ans = 0
        ans_target.append(ans)
    
    # 正解率を出す
    accuracy = 0
    for i in range(n_test):
        if ans_target[i] == test_target[i]:
            accuracy += 1
    accuracy /= n_test

    # print(w)
    # 正解率を返す
    return accuracy

# パーセプトロンの正解率を出す
print('パーセプトロン')
max_accuracy = 0
max_learning_rate = 0
for learning_rate in range(1, 11):
    accuracy = perceptron(learning_rate)
    if accuracy > max_accuracy:
        max_accuracy = accuracy
        max_learning_rate = learning_rate
    print(f'learning_rate : {learning_rate}, accuracy : {accuracy}')
print(f'max_accuracy\nlearning_rate : {max_learning_rate}, accuracy : {max_accuracy}')
# 思ったよりめちゃくちゃ低い。。。線形分離不可能だから？

# ニューラルネットワークでやってみる
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
import numpy as np

titanic_data_list = []
titanic_target_list = []
with open('titanic_test.csv') as f:
    for line in f:
        line = line.rstrip()
        if line[0] == '"':
            continue
        pclass, age, sibsp, parch, fare, sex, survived = line.split(',')
        one = []
        one.append(data.pclass)
        one.append(data.age)
        one.append(data.sibsp)
        one.append(data.parch)
        one.append(data.fare)
        one.append(data.sex)
        titanic_data_list.append(one)
        titanic_target_list.append(survived)

X = np.array(titanic_data_list)
y = np.array(titanic_target_list)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=0)
clf = MLPClassifier(solver="sgd",random_state=0,max_iter=10000,)
clf.fit(X_train, y_train)
print('ニューラルネットワーク')
print (clf.score(X_test, y_test))
# ニューラルネットでも思ったより低い。。。なぜ？
# 結局最初に実装したk近傍法が一番正解率が高かった