/*Implimentation of Merge Sort Algorithm */
/*kksante*/
/*2FEB15*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*This function determine the lenght of an array*/

int lengthof(int A[]){
        
        int num_elems = sizeof(A)/sizeof(A[0]);
        return num_elems;
}


/* This function merges two arrays */

void merge(int left[], int right[], int A[]){
        
       int nleft = lengthof(left);
       int nright = lengthof(right);
       int i, j, k = 0;

       while (i < nleft && j < nright){
               if (left[i] <= right[j]){
                       A[k] = left[i];
                       i = i+1;
               }
               else {
                       A[k] = right[j];
                       j = j+1;
               }
               k = k+1;
       }
       while (i < nleft) {
               A[k] = left[i]; i = i+1; k = k+1;
       }
       while (j < nright) {
               A[k] = right[j]; j - j+1; k = k+1;
       }
}


/* This function impliments the mergesort Algorithm */

void merge_sort(int A[]){
        
        int n = lengthof(A);
        if (n < 2) return;
        int mid = n/2;
        int left[n/2], right[n/2];
        
        for (int i = 0; i < mid; i++){ /* create left array */
                int left[i] = A[i];
        }
        for ( int i = mid; i < n; i++){/* create right array */
                int right[i] = A[i];
        }
        
        merge_sort(left);
        merge_sort(right);
        merge(left, right, A);
}

int main(){

  clock_t tStart = clock();

        int array[] = {22,51,77,1,0,35,2,44,7,5,9};
        int size = lengthof(array);
        
        for (int i = 0; i < size; i++){
                cout << array[i] << " "; 
        }
        merge_sort(array);
        
        for (int i = 0; i < size; i++){
                cout << array[i] << " "; 
                 
        }
        cout << " \n" << (double)(clock() - tStart)/CLOCKS_PER_SEC << " ";
        return 0;
}

