#include<stdio.h>
int canMoveLeft(int index,int state);
int canMoveRight(int index,int state);
int canMoveUp(int index,int state);
int canMoveDown(int index,int state);
int isSumPrime(int fst,int snd,int state);
int getNumberAtIndex(int index,int state);
int tenToThePower(int i);
int swapPlaces(int fst,int snd,int state);
int push(int number);
int pop();
int isEmpty();
int isFull();

int front = 0,rear = -1;
int itemCount = 0;
int *queue,*visited,*weight;
int main(){
    
    queue  = (int *) malloc(987654321 * sizeof(int));
    visited  = (int *) malloc(987654321 * sizeof(int));
    weight  = (int *) malloc(987654321 * sizeof(int));

     push(123456789);
    weight[123456789] = 0;
    
    while(isEmpty()!=1){
        
        int state = pop();
        visited[state] = 1;
        // printf("%d\n",state);
        for(int i=0;i<9;i++){
        
            if(canMoveLeft(i,state)){
                // printf("L");
                int newState = swapPlaces(i,i-1,state);
                if(visited[newState]!=1){
                    push(newState);
                    visited[newState] =1;
                     weight[newState] = weight[state]+1;
                }
                
               
            }

            if(canMoveRight(i,state)){
                // printf("R");
                int newState = swapPlaces(i,i+1,state);
                if(visited[newState]!=1){
                    push(newState);
                    visited[newState] =1;
                     weight[newState] = weight[state]+1;
                }
               
            }

            if(canMoveUp(i,state)){
                // printf("U");
                int newState = swapPlaces(i,i-3,state);
                if(visited[newState]!=1){
                    push(newState);
                    visited[newState] =1;
                    weight[newState] = weight[state]+1;
                }
                
            }

            if(canMoveDown(i,state)){
                // printf("D");
                int newState = swapPlaces(i,i+3,state);
                if(visited[newState]!=1){
                    push(newState);
                    visited[newState] =1;
                    weight[newState] = weight[state]+1;
                }
                
            }
            
        }

        
         
    }

    int testCase = 0;
    scanf("%d",&testCase);
    int loop = testCase;
    int result[testCase];
    while(loop){
        loop--;
        int querryState = 0;
        for(int i=0;i<9;i++){
            int n=0;
            scanf("%d",&n);
            querryState  = querryState*10 +n;
        }
        if(visited[querryState]==1){
           result[testCase-loop-1] = weight[querryState];
        }else{
          result[testCase-loop-1] = -1;
        }
    }
    for(int i =0;i<testCase;i++){
        printf("%d\n",result[i]);
    }
    
    
}

int push(int number) {
   if(!isFull()) {
      if(rear == 987654321-1) {
         rear = -1;            
      }       

      queue[++rear] = number;
      itemCount++;
   }
}
int isEmpty() {
   if(itemCount == 0){
       return 1;
   }
   return 0;
}

int isFull() {
   if(itemCount == 987654321){
       return 1;
   }
   return 0;
}

int pop() {
   int data = queue[front++];
	
   if(front == 987654321) {
      front = 0;
   }
	
   itemCount--;
   return data;  
}


int canMoveLeft(int index,int state){
    if(index%3!=0){
        if(isSumPrime(index,index-1,state)){
            return 1;
        }
    }
    return 0;
}
int canMoveRight(int index,int state){
    if((index+1)%3!=0){
        if(isSumPrime(index,index+1,state)){
            return 1;
        }
    }
    return 0;
}

int canMoveUp(int index,int state){
    if((index-3)>=0){
        if(isSumPrime(index,index-3,state)){
            return 1;
        }
    }
    return 0;
}

int canMoveDown(int index,int state){
    if(index+3<=0){
        if(isSumPrime(index,index+3,state)){
            return 1;
        }
    }
    return 0;
}

int isSumPrime(int fst,int snd,int state){
     int num = getNumberAtIndex(fst,state)+getNumberAtIndex(snd,state);
     if(num==2||num==3||num==5||num==7||num==11||num==13||num==17)
        return 1;
    return 0;
}


int getNumberAtIndex(int index,int state){
    return (state/(tenToThePower(9-index-1)))%10;
}

int tenToThePower(int i){
    int pow = 1;
    for(int j = 0;j<i;j++){
        pow*=10;
    }
    return pow;
}

int swapPlaces(int fst,int snd,int state){
    int fstNo = getNumberAtIndex(fst,state);
    int scdNo = getNumberAtIndex(snd,state);
    int firstPart = state - (fstNo*tenToThePower(9-fst-1));
    int secondPart = firstPart - (scdNo*tenToThePower(9-snd-1));
    secondPart= secondPart + (scdNo*tenToThePower(9-fst-1))+ (fstNo*tenToThePower(9-snd-1));
    return secondPart;
}