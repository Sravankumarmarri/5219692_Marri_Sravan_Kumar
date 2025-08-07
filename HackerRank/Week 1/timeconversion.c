#include<stdio.h>
#include<string.h>
int main(){
    char tm[11];
    scanf("%s",tm);
    int hh;
    int mm;
    int ss;
    char suffix[3];
    sscanf(tm ,"%2d:%2d:%2d%2s",&hh,&mm,&ss,suffix);
    if(strcmp(suffix,"AM")==0){
        if(hh==12){
            hh=0;
        }
        
    }
    else{
        if(hh!=12)
        hh+=12;
    }
    printf("%02d:%02d:%02d",hh,mm,ss);
    
    return 0;
}
