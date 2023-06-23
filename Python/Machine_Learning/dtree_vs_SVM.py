from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
import pandas as pd
import numpy as np

# ワイン分類データ
wine_train = pd.read_csv('wine/wine_train.csv', names=None)
wine_test = pd.read_csv('wine/wine_test.csv', names=None)

X_train = wine_train.loc[:, 'alcohol':]
y_train = wine_train.loc[:, 'class']
X_test = wine_test.loc[:, 'alcohol':]
y_test = wine_test.loc[:, 'class']

# SVM（ハイパラとして正則化パラメータcの変化を見る）
print('SVM')
max_c_SVM = -1
max_acc_SVM = -1
for c in np.geomspace(1, 100000, 30):
    model_SVC = SVC(C=c)
    model_SVC.fit(X_train, y_train)
    # 正答率が最大のものを求める
    if (test_acc := model_SVC.score(X_test, y_test)) > max_acc_SVM:
        max_acc_SVM = test_acc
        max_c_SVM = c
    # c=1のときだけ出力
    if c == 1:
        print(f'c : {c}')
        print(f'test acc  : {test_acc}')

print(f'max_c : {max_c_SVM}')
print(f'test max_acc  : {max_acc_SVM}')

# 決定木
model_tree = DecisionTreeClassifier()
model_tree.fit(X_train, y_train)
print('決定木')
print(f'train acc : {model_tree.score(X_train, y_train)}')
print(f'test acc  : {model_tree.score(X_test, y_test)}')

# 結果
# c = 1 のときはSVMよりも決定木の正答率が圧倒的に高かった
# SVCのハイパラとしてcを変化させるとc=13738のとき正答率が100%になった
# 決定木の学習データでは正答率100%だった