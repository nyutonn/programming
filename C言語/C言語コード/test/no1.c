#include <stdio.h>

int main(){
    int n = 9;  //  配列の要素数
    int a[] = {8, 3, 1, 9, 2, 4, 7, 6, 5};  //  配列
    int cnt = 0;  //  比較回数のカウント
    for(int i = 0; i < n; i += 2){  //  半分にわける
        cnt ++;
        if(a[i] > a[i+1]){
            int tmp = a[i];
            a[i] = a[i+1];
            a[i+1] = tmp;
        }
    }
    int min = a[0];  //  最小値
    for(int i = 2; i < n; i += 2){  //  最小値を探す
        cnt ++;
        if(min > a[i]) min = a[i];
    }
    int max = a[1];  //  最大値
    for(int i = 3; i < n; i += 2){  //  最大値を探す
        cnt++;
        if(max < a[i]) max = a[i];
    }
    printf("min : %d\nmax : %d\ncount : %d\n", min, max, cnt);
}