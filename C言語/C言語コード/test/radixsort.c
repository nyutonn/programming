#include  <stdio.h>
void RadixSort(int x[ ], int n, int r);
void ShowData(int x[ ], int n);
void main(void);
#define N 11
static int rad[N];    // バケット配列
static int y[N];      // コピーに使う配列
  //  基数ソート
void RadixSort(int x[ ], int n, int r)  {                   
    int i, j, k;                      
    int m = 1, keta = 1;                 /* 基数を取り出す桁 */
    while (m <= r) {
        for (i = 0; i < n; i++) rad[i] = (x[i] / m) % N;   /* 基数を取り出し rad[i] に保存 */
        k = 0;                          /* 配列の添字として使う */
        for (i = 0; i < N; i++)        /* 基数は 0 から N-1 */
            for (j = 0; j < n; j++)
                if (rad[j] == i)        /* 基数の小さいものから */
                    y[k++] = x[j];      /* y[ ] にコピー */

        for (i = 0; i < n; i++) x[i] = y[i];  /* x[ ] にコピーし直す */

        printf("    %d桁目のソート: ", keta);
        ShowData(x, n);             /*  途中経過を表示  */		
        m *= N; keta++;                       /*  基数を取り出す桁を一つ上げる */
    }
}

  // n 個のデータを表示する 
void ShowData(int x[ ], int n){
    for (int i = 0; i < n ; i++) printf("%d ", x[i]);
    printf("\n");
}

void main(void){
    int x[N] = { 121, 11, 13310, 1331, 25, 101, 2, 80, 1001, 7, 1 };
    int n = N;        /* ソートするデータ数 */
    int r = 10*n*n*n;      /* ソートするデータから取り出す基数の上限 */
    printf("ソート前: ");
    ShowData(x, n);
    RadixSort(x, n, r);
    printf("ソート後: ");
    ShowData(x, n);
}