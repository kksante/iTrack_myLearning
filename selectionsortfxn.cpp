/*This is the selection sort algorithm implimentation*/
/*kksante*/
/*21JAN15*/

#include <iostream>

using namespace std;

void selectionsort(int A[], int n) {

        for(int i = 0; i < n-1; i++) { // we need to do n-2 passes
                int iMin = i; /*ith position: elements from i till n-1
                                are candidates*/
                for (int j = i+1; j<n; j++) {
                        if (A[j] < A[iMin])
                                iMin = j; /*update the index
                                            of min element*/
                }
                int temp = A[i];
                A[i] = A[iMin];
                A[iMin] = temp;
        }
}

int main() {

        int A[] = {1,37,4,2,5,3};
        selectionsort(A,6);
        for(int i = 0; i < 6; i++){
                cout << A[i] << " ";
        }
        return 0;
        
}
