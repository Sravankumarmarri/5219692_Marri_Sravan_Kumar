#include<stdio.h>
int main(){
    long long arr[5],temp,min_sum=0,max_sum=0;
    for(int i=0;i<5;i++){
        scanf("%lld",&arr[i]);
    }
     for (int i = 0;i<5-1;i++) {
        for (int j=i+1;j<5;j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i=0;i<4;i++){
        min_sum+=arr[i];
    }
    for(int i=1;i<5;i++){
        max_sum+=arr[i];
    }
    printf("%lld %lld",min_sum,max_sum);
    return 0;
}

/* here i have taken arr[5] array. since size is fixed directly i have taken 5.
firstly i have sorted the array using temperary variable temp.
after sorting in ascending order, i have calculated min sum with first 4 elements in arr.
next max sum using last 4 elements in arr. i.e except first element.

initially i have taken int as data type for all my variables but only few test cases satisfied
so i have gone for long long data type */