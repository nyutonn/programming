#include <stdio.h>

int main(){
    int n = 3, b = -2;  //  配列の要素数, 総和
    int a[] = {4, -3, 5};  //  配列
    int sum_plus = 0, sum_minus = 0;  //  正の和と負の和
    for(int i = 0; i < n; i++){
        if(a[i] > 0) sum_plus += a[i];  //  正の和
        else if(a[i] < 0) sum_minus -= a[i];  //  負の和
    }
    if(sum_plus < b) {
        printf("Impossible...\n");  //  正の和 < b のとき、bは作れない
        return 0;
    }
    int dp1[n+1][sum_plus+1];   //  1 : true, 0 : false, 正の範囲を扱う
    int dp2[n+1][sum_minus+1];  //  1 : true, 0 : false, 負の範囲を扱う
    for(int i = 0; i <= n; i++) dp1[i][0] = 1; 
    for(int i = 0; i <= n; i++) dp2[i][0] = 1; 
    for(int j = 1; j <= sum_plus; j++)  dp1[0][j] = 0; 
    for(int j = 1; j <= sum_minus; j++) dp2[0][j] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum_plus; j++){  //  正の範囲
            if(dp1[i-1][j] == 1) dp1[i][j] = 1;  //  上が1のとき
            else if(sum_minus*(-1) <= j-a[i-1] && j-a[i-1] < 0 && dp2[i-1][-(j-a[i-1])]) dp1[i][j] = 1;  //  負から正にまたぐとき
            else if(0 <= j-a[i-1] && j-a[i-1] <= sum_plus && dp1[i-1][j-a[i-1]]) dp1[i][j] = 1;  // 左を見る
            else dp1[i][j] = 0;
        }
        for(int j = 1; j <= sum_minus; j++){  // 負の範囲
            if(dp2[i-1][j] == 1) dp2[i][j] = 1;  //  上が1のとき
            else if (sum_plus*(-1) < j+a[i-1] && j+a[i-1] < 0 && dp1[i-1][-(j+a[i-1])]) dp2[i][j] = 1;  //  正から負へまたぐとき
            else if(0 <= j+a[i-1] && j+a[i-1] <= sum_minus && dp2[i-1][j+a[i-1]]) dp2[i][j] = 1;  //  右を見る
            else dp2[i][j] = 0;
        }
    }
    //  入力の表示
    printf("a[i] = {");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("}, b = %d\n", b);
    for(int i=0; i<=n; i++){  //  dp配列表示
        for(int j = sum_minus; j >= 0; j--) printf("%d ", dp2[i][j]);  //  負の範囲の表示
        printf("|");  //  正と負の境目に線を入れる
        for(int j = 0; j <= sum_plus; j++) printf("%d ", dp1[i][j]);  //  正の範囲の表示
        printf("\n");
    }
    if(b >= 0 && dp1[n][b] == 1) printf("Possible!\n");  //  bが正でOKのとき
    else if(b < 0 && dp2[n][-b] == 1) printf("Possible!\n");  //  bが負でOKのとき
    else printf("Impossible...\n");
}