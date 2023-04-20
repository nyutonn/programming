#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int dp[n+1][n+1];
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int j = 0; j <= n; j++) dp[0][j] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    printf("f(%d) = %d\n", n, dp[n][n]);
    return 0;
}
