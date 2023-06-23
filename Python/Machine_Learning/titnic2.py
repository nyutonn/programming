import numpy as np

# 訓練用データを作る
train_data = []
train_target = []
with open('titanic_train.csv') as f:
    for line in f:
        line = line.rstrip()
        if line[0] == '"': continue
        *data, survived = line.split(',')
        for i, d in enumerate(data):
            data[i] = float(d)
        train_data.append(data)
        train_target.append(int(survived))

# テスト用データを作る
test_data = []
test_target = []
with open('titanic_test.csv') as f:
    for line in f:
        line = line.rstrip()
        if line[0] == '"': continue
        *data, survived = line.split(',')
        for i, d in enumerate(data):
            data[i] = float(d)
        test_data.append(data)
        test_target.append(int(survived))

n_test = len(test_target)
n_train = len(train_target)

# numpyの行列に変換する
train_data = np.array(train_data)
train_target = np.array(train_target)
test_data = np.array(test_data)
test_target = np.array(test_target)

# k近傍法から正解率を出す
def knn(k):
    ans_target = []
    # テストデータを取り出す
    for data in test_data:
        # 訓練データの中から近いやつをk個選ぶ
        distances = [] # 距離を一旦リストに入れる
        for op_data in train_data:
            distance = np.linalg.norm(op_data - data) # ユークリッド距離
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
# for k in range(1, 10):
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

from sklearn import metrics
import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier


accuracy_list = []
k_range = range(1, 100)
for k in k_range:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(train_data, train_target)
    Y_pred = knn.predict(test_data)
    accuracy_list.append(metrics.accuracy_score(test_target, Y_pred))

figure = plt.figure()
ax = figure.add_subplot(111)
ax.plot(k_range, accuracy_list)
ax.set_xlabel('k-nn')
ax.set_ylabel('accuracy')
plt.show()
