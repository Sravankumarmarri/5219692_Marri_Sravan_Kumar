#include<stdio.h>
int socks(int n,int ar[]){
    int count[101]={0};
    int pair=0;
    for(int i=0;i<n;i++){
        count[ar[i]]++;
    }
    for(int i=0;i<101;i++){
        pair+=count[i]/2;
    }
    return pair;
}
int main(){
    int n;
    scanf("%d",&n);
    int ar[n];
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    int result=socks(n,ar);
    printf("%d",result);
    return 0;
}