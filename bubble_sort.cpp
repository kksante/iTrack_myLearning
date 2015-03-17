/*Implimentation of Bubble Sort Algorithm*/
/*kksante*/
/*27JAN15*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;


/* Function to compare and swap elements in the array */
void bubble_sort(int A[], int n){
        for (int k = 1; k < n; k++) {
                int flag = 0;
                for (int i = 0; i < n-k; i++){
                        if (A[i] > A[i+1]) {
                                int temp = A[i];
                                A[i] = A[i+1];
                                A[i+1] = temp;
                                flag = 1;
                                     }
                }
                if (flag == 0) break;
        }
}


int main (){
        
        clock_t tStart = clock();
        int size = 11;
        int array[] = {22,51,77,1,0,35,2,44,7,5,9};
        bubble_sort(array, size);
        
        for (int i = 0; i < size; i++){
                cout << array[i] << " "; 
                 
        }
        cout << " \n" << (double)(clock() - tStart)/CLOCKS_PER_SEC << " ";
        return 0;
}

