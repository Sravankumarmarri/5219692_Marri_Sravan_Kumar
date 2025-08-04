#include <stdio.h>
int main(){
    int n;int positive=0;int negative=0;int zero=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            positive+=1;
        } else if(arr[i]<0){
            negative+=1;
        }else{
            zero+=1;
        }
    }
    printf("%.6f\n",(float)positive/n);
    printf("%.6f\n",(float)negative/n);
    printf("%.6f\n",(float)zero/n);
    return 0;
}

// Explanation :
/*i have taken array and i have counted no of positives , no of negatives and no of zeros . 
then i have divided using total no of elements in array to get probability of occurance
here %.6f for 6 digits floating value */