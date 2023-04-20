#include <stdio.h>

void write(int *v){
    
}

int main(){
    int v[3][3] = {};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            v[i][j] = 3*i + j + 1;
        }
    }

    for(int i=2; 0 <= i; i--){
        for(int j=0; j<3; j++){
            if(v[i][j] == 3*i+j+1) printf("%d", v[i][j]);
            if(j != 2) printf("|");
        }
        if(i != 0) printf("\n-+-+-\n");
        else printf("\n");
    }
    //write(v);
}
