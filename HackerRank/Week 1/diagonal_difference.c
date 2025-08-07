#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;int sum_LR=0;int sum_RL=0;
    scanf("%d",&n);
    int m[n][n];
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&m[i][j]);
        }
    }
    for (int i=0;i<n;i++){
        sum_LR=sum_LR+m[i][i];
        sum_RL+=m[i][n-i-1];
    }
    int diff=abs(sum_LR - sum_RL);
    printf("%d\n",diff);
}
