/*Implimentation of Insertion Sort Algorithm */
/*kksante*/
/*31JAN15*/

#include <iostream>
#include <cstdlib>

using namespace std;

/* Function to insert elements into their right place in a sorted 
   array*/

void insertion_sort(int A[], int n){
        
        for(int i = 1; i < n; i++){
                int value = A[i];
                int hole = i;
                while(hole > 0 && A[hole - 1] > value){
                        A[hole] = A[hole-1];
                        hole = hole - 1;
                }
                A[hole] = value;
        }
}


int main(){

  clock_t tStart = clock();
        int size = 11;
        int array[] = {22,51,77,1,0,35.2,44,7,5,9};
        insertion_sort(array, size);
        
        for (int i = 0; i < size; i++){
                cout << array[i] << " "; 
                 
        }
        cout << " \n" << (double)(clock() - tStart)/CLOCKS_PER_SEC << " ";
        return 0;
}
