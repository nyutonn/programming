import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('a.png')

# マスク
# 平滑化フィルタ
avg_kernel = np.ones((5,5),np.float32)/25
avg_dst = cv2.filter2D(img,-1,avg_kernel)

 # ちょいうすく
light_kernel = np.array([[1/10, 1/10, 1/10], [1/10, 1/10, 1/10], [1/10, 1/10, 1/10]]) 
light_dst = cv2.filter2D(img,-1,light_kernel)

# 黒くして下側の影のみ残す
under_kernel = np.array([[0, -1, 0], [0, 1, 0], [0, 0, 0]])  
under_dst = cv2.filter2D(img,-1,under_kernel)

# 黒くして右下側の影のみ残す
underRight_kernel = np.array([[-1, 0, 0], [0, 1, 0], [0, 0, 0]])  
underRight_dst = cv2.filter2D(img,-1,underRight_kernel)


# 黒くして右下側の影のみ残す
Right_kernel = np.array([[0, 0, 0], [0, -1, 1], [0, 0, 0]])  
Right_dst = cv2.filter2D(img,-1,Right_kernel)

# 黒くして右下側の影のみ残す
Right2_kernel = np.array([[0, 0, 1], [0, -1, 0], [0, 0, 0]])  
Right2_dst = cv2.filter2D(img,-1,Right2_kernel)

# 黒くして上側の影のみ残す
Up_kernel = np.array([[1/4, 1/2, 1/4], [-1/4, -1/2, -1/4], [0, 0, 0]])  
Up_dst = cv2.filter2D(img,-1,Up_kernel)

plt.subplot(421),plt.imshow(img),plt.title('Original')
plt.xticks([]), plt.yticks([])
plt.subplot(422),plt.imshow(avg_dst),plt.title('Averaging')
plt.xticks([]), plt.yticks([])
plt.subplot(423),plt.imshow(light_dst),plt.title('Lighting')
plt.xticks([]), plt.yticks([])
plt.subplot(424),plt.imshow(under_dst),plt.title('Under')
plt.xticks([]), plt.yticks([])
plt.subplot(425),plt.imshow(underRight_dst),plt.title("Under_Right")
plt.xticks([]), plt.yticks([])
plt.subplot(426),plt.imshow(Right_dst),plt.title("Right")
plt.xticks([]), plt.yticks([])
plt.subplot(427),plt.imshow(Right2_dst),plt.title("Up_Right2")
plt.xticks([]), plt.yticks([])
plt.subplot(428),plt.imshow(Up_dst),plt.title("Up")
plt.xticks([]), plt.yticks([])

plt.show()