#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes
int random1to100();
void printAr(int numAr[], int numArSize);
int checkNum(int numAr[], int numArSize);
int searchNum(int numAr[], int numArSize, int target); // Linear Search 
void sortAr(int numAr[], int numArSize);             
int binarySearch(int numAr[], int numArSize, int target); // ????? Binary Search
 int N, target, i,j;
int main() {
    int A[100];
    int N, target, i;
    
    srand(time(NULL));

    printf("Enter N (1-100): ");
    scanf("%d", &N);
    if (N > 100) N = 100;
    if (N < 1) N = 1;

    // Array
    for (i = 0; i < N; i++) {
        A[i] = checkNum(A, i); 
    }

    // Sort Binary Search ???
    sortAr(A, N);
    printf("Sorted Array: ");
    printAr(A, N);

  
    printf("Enter target to search (Binary Search): ");
    scanf("%d", &target);

    //Binary Search
    int resultIndex = binarySearch(A, N, target);
    
    if (resultIndex != -1) {
        printf("Found %d at index %d (using Binary Search)\n", target, resultIndex);
    } else {
        printf("Target %d not found.\n", target);
    }

    return 0;
}

//Functions

int binarySearch(int numAr[], int numArSize, int target) {
    int left = 0;
    int right = numArSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (numAr[mid] == target) return mid; 
        
        if (numAr[mid] < target) 
            left = mid + 1; 
        else 
            right = mid - 1; 
    }
    return -1; 
}

void sortAr(int numAr[], int numArSize) {
    int i, j, min_idx, temp;
    for (i = 0; i < numArSize - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < numArSize; j++)
            if (numAr[j] < numAr[min_idx])
                min_idx = j;
        
        // (Swap)
        temp = numAr[min_idx];
        numAr[min_idx] = numAr[i];
        numAr[i] = temp;
    }
}

int random1to100() {
    return (rand() % 100) + 1;
}

int checkNum(int numAr[], int numArSize) {
    int rnum;
    do {
        rnum = random1to100();
    } while (searchNum(numAr, numArSize, rnum) != -1);
    return rnum;
}

int searchNum(int numAr[], int numArSize, int target) {
    for (j = 0; j < numArSize; j++) {
        if (numAr[j] == target) return j;
    }
    return -1;
}

void printAr(int numAr[], int numArSize) {
    for (j = 0; j < numArSize; j++) {
        printf("%d ", numAr[j]);
    }
    printf("\n");
}
