#include <stdio.h>
#define n 11  //  基数、進数、バケツの数

void show(int array[]){  //  配列の表示
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");
}

void countSort(int array[], int array_size, int exp) {
    int sorted_array[array_size];  //  ソートした後に格納する配列
    int count[n] = {0};  //  バケット配列
    for (int i = 0; i < array_size; i++) {  // バケット配列に入れる
        count[(array[i] / exp) % n]++;
    }
    for (int i = 1; i < n; i++) {  //  バケット配列で累積和を取る
        count[i] += count[i - 1];
    }
    for (int i = array_size - 1; i >= 0; i--) {  //  基数が小さい順に新しい配列に格納
        sorted_array[count[(array[i] / exp) % n ] - 1] = array[i];
        count[(array[i] / exp) % n]--;
    }
    for (int i = 0; i < array_size; i++) {  //  元の配列に戻す
        array[i] = sorted_array[i];
    }
}

void radixSort(int array[], int array_size) {
    int max = array[0];
    for(int i = 1; i < array_size; i++) {  // 配列の最大値を見つける
        if(array[i] > max) max = array[i];
    }
    int cnt = 0;
    for (int exp = 1; max / exp > 0; exp *= n) {  // 基数ソートの実装
        cnt++;
        countSort(array, array_size, exp);
        printf("%d回目   : ", cnt);
        show(array);
    }
}

int main (void) {
    int array[] = {1331, 121, 11, 1330, 120, 10, 132, 135, 339, 8000, 1203 };
    printf("ソート前: ");
    show(array);
    radixSort(array, sizeof(array) / sizeof(array[0]));
    printf("ソート後: ");
    show(array);
    return 0;
}