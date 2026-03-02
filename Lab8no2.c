#include <stdio.h>

int std[8],i,j,oneans,stat ;
int checkscore(int index);
int chceck1(int index);
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
    
    
    for( i = 0 ;i<8;i++){
        printf("std %d => Score: %d\n", i+1, checkscore(i));
        if(oneans==1){
        	printf("show number of no.1 stat :  %d\n",++stat);//check
		}
		oneans = 0;
    }
        return 0;
    }


    

int checkscore(int index){
    int currentScore = 0;
        for ( j = 0; j < 10; j++) {
        
            if (ans[index][j] == charkeys[j]) {
                currentScore++;
                std[index] = currentScore;
            }
            
            
        }chceck1(index);
        return currentScore;
        
}
int chceck1(int index){
		if(ans[index][0]==charkeys[0]){
        		oneans = 1;
			}
}
