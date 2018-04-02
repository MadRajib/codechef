#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int fingers;
        
        scanf("%d",&fingers);
        int fingersLength[fingers];
        int gloveLength[fingers];
        for(int i=0;i<fingers;i++){
            int len;
            scanf("%d",&len);
            fingersLength[i]= len;
        }
        int front=1,back=1;
        for(int i=0;i<fingers;i++){
            int len;
            scanf("%d",&len);
            gloveLength[i]= len;
            if(len<fingersLength[i] && front!=0){
                   front = 0;
            }

            if(len<fingersLength[fingers-1-i] && back!=0){
                   back = 0;
            }

        }

        if(back && front){
            printf("both\n");
        }else if(front){
            printf("front\n");
        }else if(back){
            printf("back\n");
        }else{
            printf("none\n");
        }
    }
}