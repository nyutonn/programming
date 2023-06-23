# 不純度を求める
def purity(s, ve, vi):
    cnt_sum = s + ve + vi
    return (cnt_sum - max(s, max(ve, vi))) / cnt_sum

import numpy as np
from sklearn.datasets import load_iris
iris = load_iris()
X = iris.data
y = iris.target
X_y = []
for i in range(len(X)):
    X_y.append([])
    for j in range(4):
        X_y[i].append(X[i][j])
    X_y[i].append(y[i])
X_y = np.array(X_y)

# 初期化
I_Qy_min = 10000
I_Qn_min = 10000
d_min = 0
theta_min = -1

# 特徴量4つぶん回す
for d in range(4):
    print(d)
    # d個目の特徴量でソートする
    X_y_temp = X_y[X_y[:, d].argsort(), :]
    print(X_y_temp)
    # カウントの初期化
    setosa_cnt = 0
    versicolor_cnt = 0
    virginica_cnt = 0
    # データ全体を回す
    for i, xy in enumerate(X_y):
        # 最後は0で割ることになるので省略
        if i == 149:
            break
        # カウントする
        if xy[4] == 0:
            setosa_cnt += 1
        elif xy[4] == 1:
            versicolor_cnt += 1
        else:
            virginica_cnt += 1
        # 不順度計算
        I_Qy = purity(setosa_cnt, versicolor_cnt, virginica_cnt)
        I_Qn = purity(50 - setosa_cnt, 50 - versicolor_cnt, 50 - virginica_cnt)
        # 最小の不順度を求める
        if I_Qy_min + I_Qn_min > I_Qy + I_Qn:
            I_Qy_min = min(I_Qy_min, I_Qy)
            I_Qn_min = min(I_Qn_min, I_Qn)
            d_min = d
            theta_min = i
# 表示
print(f'最適な次元 : {d_min}')
print(f'そのときの閾値 : {theta_min}')
print(f'I(Qy) = {I_Qy_min}')
print(f'I(Qn) = {I_Qn_min}')
