#include <stdio.h>

void Sort(int numAr[], int numArSize);

int main() {
    int arr1[] = {3, 6, 2, 4}, arr2[] = {3, 6, 2, 4}, top[3], i, j, temp;

    printf("แนวทางที่ 1\n");
   
    for (i = 0; i < 3; i++) {
        int maxIndex = 0;
        for (j = 1; j < 4; j++) {
            if (arr1[j] > arr1[maxIndex]) {
                maxIndex = j;
            }
        }
        top[i] = arr1[maxIndex];
        arr1[maxIndex] = -1; 
        printf("%d ", top[i]);
    }
    
    printf("\n\nแนวทางที่ 2\n");
  
    Sort(arr2, 4); 
    

    for (i = 1; i < 4; i++) {
        top[i-1] = arr2[i];
    }

  
    for (i = 0; i < 3 - 1; i++) {
        for (j = 0; j < 3 - i - 1; j++) {
            if (top[j] < top[j+1]) { 
                temp = top[j];
                top[j] = top[j+1];
                top[j+1] = temp;
            }
        }
    }

   
    for (i = 0; i < 3; i++) {
        printf("%d ", top[i]);
    }

    return 0;
}

void Sort(int numAr[], int numArSize) {
    int i, j, temp;
    for (i = 0; i < numArSize - 1; i++) {
        for (j = 0; j < numArSize - i - 1; j++) {
            if (numAr[j] > numAr[j+1]) {
                temp = numAr[j];
                numAr[j] = numAr[j+1];
                numAr[j+1] = temp;
            }
        }
    }
}