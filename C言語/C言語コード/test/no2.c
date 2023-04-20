#include <stdio.h>

int main(){
    int n = 4, b = 9;  //  配列の要素数, 総和
    int a[] = {5, 2, 0, 1};  //  配列
    int dp[n+1][b+1];  //  1 : true, 0 : false
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int j = 1; j <= b; j++) dp[0][j] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= b; j++){
            if(dp[i-1][j]) dp[i][j] = 1;
            else if(j-a[i-1] >= 0 && dp[i-1][j-a[i-1]]) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }
    for(int i=0; i<=n; i++){  //  dp配列の表示
        for(int j=0; j<=b; j++) printf("%d ", dp[i][j]);
        printf("\n");
    }
    if(dp[n][b]) printf("Possible!\n");
    else printf("Impossible...\n");
}