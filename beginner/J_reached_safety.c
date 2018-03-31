#include<stdio.h>
int main(){
    int t,_case=0;
    scanf("%d",&t);
    while(t--){
        int M,N,Rx,Ry,numberOfSteps,dx=0,dy=0;
        
        scanf("%d %d",&M,&N);
        scanf("%d %d",&Rx,&Ry);
        scanf("%d",&numberOfSteps);
        char steps[numberOfSteps];

        scanf("%s",steps);
        for(int i=0;i<numberOfSteps;i++){
            char step = steps[i];
            if(step=='l'||step=='L'){
                dx-=1;
            }
            if(step=='r'||step=='R'){
                dx+=1;
            }
            if(step=='u'||step=='U'){
                dy+=1;
            }
            if(step=='d'||step=='D'){
                dy-=1;
            }
        
        }
        _case++;
        
        if((dx<0||dx>M)||(dy<0||dy>N)){
            printf("Case %d: DANGER\n",_case);
        }else if((dx==Rx) &&(dy ==Ry)){
            printf("Case %d: REACHED\n",_case);
        }else{
            printf("Case %d: SOMEWHERE\n",_case);
        }


    }
}