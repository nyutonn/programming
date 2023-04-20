#include <stdio.h>

int main(){
    int n = 3, k = 3;
    // scanf("%d%d", &n, &k);
    int dp[n+1][n+1][k+1];
    for(int i=0; i<=n; i++)for(int j=0; j<=n; j++)for(int x=0; x<=n; x++) dp[i][j][x] = 0;
    for(int i = 0; i <= n; i++) dp[i][0][0] = 1;
    for(int j = 0; j <= n; j++) dp[0][j][0] = 1;
    // for(int i = 0; i <= n; i++)for(int k = 1; k <= n; k++) dp[i][0][k] = 1;
    // for(int j = 0; j <= n; j++)for(int k = 1; k <= n; k++) dp[0][j][k] = 1;
    for(int x = 1; x <= k; x++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == 1 && j == 1) {
                    if(x == 1) dp[1][1][1] = 2;
                    else dp[1][1][x] = 0;
                }
                else if(i == 1) dp[1][j][x] = dp[i][j-2][x] + dp[i-1][j-1][x-1];
                else if(j == 1) dp[i][1][x] = dp[i-2][j][x] + dp[i-1][j-1][x-1];
                else dp[i][j][x] = dp[i-2][j][x] + dp[i][j-2][x] + dp[i-1][j-1][x-1];
            }
        }
    }
    // printf("f(%d, %d) = %d\n", n, k, dp[3][1][1]);
    for(int x = 0; x <= k; x++){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                printf("%d ", dp[i][j][x]);
            }
            printf("\n");
        }
        printf("\n");
    }            
    return 0;
}
