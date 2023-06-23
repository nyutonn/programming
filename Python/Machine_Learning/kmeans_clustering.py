import numpy as np
import pandas as pd
from sklearn.datasets import load_iris
import matplotlib.pyplot as plt

np.random.seed(0)

# データ間の距離を求める
def data_distance(data1, data2):
    return np.linalg.norm(data1 - data2)

# クラスタ間の平均距離を求める
# 関数作ったけど使わなかった
def cluster_distance(cluster1, cluster2):
    distance = 0
    for data1 in cluster1:
        for data2 in cluster2:
            distance += data_distance(data1, data2)
    distance /= len(cluster1) * len(cluster2)
    return distance

# クラスタの重心を求める
def cluster_center(cluster):
    # クラスタが空のときは重心を求められないので、0を返す
    if len(cluster) == 0:
        return np.zeros(1)
    center = np.zeros(len(cluster[0]))
    for data in cluster:
        center += data
    center /= len(cluster)
    return center

# k-means法
def kmeans(k, data):
    # データをk個のクラスタに分ける
    # データをランダムにk個のクラスタに分ける
    clusters = []
    for i in range(k):
        clusters.append([])
    for i in range(len(data)):
        clusters[np.random.randint(0, k)].append(data[i])
    
    # クラスタをk個の重心に移動する
    while True:
        # 重心を求める
        centers = []
        for cluster in clusters:
            centers.append(cluster_center(cluster))
        
        # クラスタを変更
        new_clusters = []
        # k個のクラスタを初期化
        for i in range(k):
            new_clusters.append([])
        for cluster in clusters:
            for data in cluster:
                min_distance = 1000000000
                min_index = 0
                # 一番近い重心を求めて、そのクラスタに入れる
                for i in range(k):
                    distance = data_distance(data, centers[i])
                    if distance < min_distance:
                        min_distance = distance
                        min_index = i
                new_clusters[min_index].append(data)
        
        # クラスタが変化しなくなったら終了
        if np.array_equal(clusters, new_clusters):
            return clusters
        else:
            clusters = new_clusters


iris = load_iris()
clusters = kmeans(5, iris.data)
# 元データを描く
plt.scatter(iris.data[:, 0], iris.data[:, 1], c=iris.target, s=5)
# クラスタリング結果を描く
for cluster in clusters:
    if cluster == clusters[0]:
        ec = 'g'
    elif cluster == clusters[1]:
        ec = 'y'
    elif cluster == clusters[2]:
        ec = 'b'
    elif cluster == clusters[3]:
        ec = 'r'
    else:
        ec = 'k'
    plt.scatter([data[0] for data in cluster], [data[1] for data in cluster], facecolor='none', edgecolors=ec)
# 重心を描く
print([cluster_center(cluster)[0] for cluster in clusters])
print(clusters)
print([cluster_center(cluster)[1] for cluster in clusters])
plt.scatter([cluster_center(cluster)[0] for cluster in clusters], [cluster_center(cluster)[1] for cluster in clusters], s=100, marker='*', c='r')
plt.xlabel('Sepal Length')
plt.ylabel('Sepal Width')
plt.show()
