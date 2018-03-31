#include<stdio.h>
int main(){
    int t,_case= 1;
    scanf("%d",&t);
    while(t--){
        int L,K,count=0;
        scanf("%d %d",&L,&K);
        for(int i= L;i>0;i--){
            int shift = K;
            while(shift<=i){
                count ++;
                shift++;
            }
        }

        printf("Case %d: %d\n",_case++,count);
        
    }
}