/*This is an implimentation of selectionsort algorithm*/
/*kksante*/
/*21JAN15*/

#include<stdio.h>


void selectionsort(int A[], int n) {
        int i, j;
                for(i = 0; i < n-1; i++) { // we need to do n-2 passes
                        int iMin = i; /*ith position: elements from 
                                        i till n-1 are candidates*/
                        for(j = i+1; j < n; j++) {
                                if (A[j] < A[iMin])
                                        iMin = j; /*update the index
                                                    of min element*/
                        }
                int temp = A[i];
                A[i] = A[iMin];
                A[iMin] = temp;
        }
}

int main() 
{
        int A[11] = {23, 494, 1, 3, 586, 234234, 2, 9, 6, 8, 6};
        selectionsort(A, 11);
        int i;
        for(i = 0; i<11; i++) {
                printf ("%d ", A[i]);
        }
        return 0;
}
