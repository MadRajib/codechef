#include<stdio.h>
int checkIfGreater(int a[][3],int x, int y);

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int contestents[3][3];
        for(int i =0;i<3;i++){
            scanf("%d %d %d",&contestents[i][0],&contestents[i][1],&contestents[i][2]);
        }
        int brk = 0;
        for(int i= 0;i<3;i++){
            for(int j= 0;j<3;j++){
                for(int k= 0;k<3;k++){
                    // dont compare with same contestant
                    if(i==j||i==k||k==j){
                        continue; 
                    }
                    if(checkIfGreater(contestents,j,i)&&checkIfGreater(contestents,k,j)){
                        printf("yes\n");
                        brk = 1;
                        break;
                    }
                }
                if(brk)
                    break;
            }
                if(brk)
                    break;   
        }

        if(!brk)
            printf("no\n");
    }

}

int checkIfGreater(int a[][3],int x, int y){
    // if atleast one is lower then return false;
    for(int i =0;i<3;i++){
        if(a[x][i]<a[y][i]){
            return 0;
        }
    }
    // nothing is lower that means if anyone turns out be higher return true
    for(int i =0;i<3;i++){
        if(a[x][i]>a[y][i]){
            return 1;
        }
    }
    
    return 0;
    
}   