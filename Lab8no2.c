#include <stdio.h>

int std[8],i,j,oneans,stat,statincorrect[8][10],k,z=0;
int checkscore(int index);
int chceck1(int index);
int cal_statincorrect(int index);
int total[10];
char charkeys[10] = {'D','B','D','C','C','D','A','E','A','D'};
char ans[8][10] = {
    {'A','B','A','C','C','D','E','E','A','D'}, // Score: 7
    {'D','B','A','B','C','A','E','E','A','D'}, // Score: 6
    {'E','D','D','A','C','B','E','E','A','D'}, // Score: 5
    {'C','B','A','E','D','C','E','E','A','D'}, // Score: 4
    {'A','B','D','C','C','D','E','E','A','D'}, // Score: 8
    {'B','B','E','C','C','D','E','E','A','D'}, // Score: 7
    {'B','B','A','C','C','D','E','E','A','D'}, // Score: 7
    {'E','B','E','C','C','D','E','E','A','D'}  // Score: 7
};

int main() {
    //set value in arry to 0
    for(i=0;i<8;i++){
    	for(j=0;j<10;j++){
    		statincorrect[i][j] = 0;
		}
	}
    
    for( i = 0 ;i<8;i++){
        printf("std %d => Score: %d\n", i+1, checkscore(i));
        if(oneans==1){
        	printf("show number of no.1 stat :  %d\n",++stat);//check
		}
		oneans = 0;
    }
    //test valude
    printf("show table in correct = 0 incorrect = 1\n");
      for(i=0;i<8;i++){
    	for(j=0;j<10;j++){
    		printf("%d ",statincorrect[i][j]);
		}
		printf("\n");
	}
	printf("show table static\n");
	for(i=0;i<10;i++){
		printf("%d ",total[i]);
	}
int max_val = total[0];
int max_index = 0;
for(k = 1; k < 10; k++) {
    if(total[k] > max_val) {
        
        max_index = k;
    }
}
printf("\n");
printf("the most incorrect no.%d \n", max_index + 1);
        return 0;
    }


    

int checkscore(int index){
    int currentScore = 0;
        for ( j = 0; j < 10; j++) {
        
            if (ans[index][j] == charkeys[j]) {
                currentScore++;
                std[index] = currentScore;
            }
			if(ans[index][j] != charkeys[j]){
            	statincorrect[index][j] = 1;
        }
        }
		chceck1(index);
        cal_statincorrect(index);
        return currentScore;
        
}
int chceck1(int index){
		if(ans[index][0]==charkeys[0]){
        		oneans = 1;
			}
}
int cal_statincorrect(int index){
    for(k=0; k<10; k++){ 
        total[k] += statincorrect[index][k]; 
    }
}


