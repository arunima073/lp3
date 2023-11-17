#include <cstdlib>  // For random number generation
#include<bits/stdc++.h>
using namespace std;

int partition( vector<int>& A, int i, int j, int pivot) {
     swap(A[j], A[pivot]);
    int store_index = i;

    for (int k = i; k < j; k++) {
        if (A[k] < A[j]) {
             swap(A[store_index], A[k]);
            store_index++;
        }
    }

     swap(A[j], A[store_index]);

    return store_index;
}

void quicksort( vector<int>& A, int i, int j) {
    if (i >= j) {
        return;
    }

    int pivot = partition(A, i, j, j);
    quicksort(A, i, pivot - 1);
    quicksort(A, pivot + 1, j);
}

void randomized_quicksort( vector<int>& A, int i, int j) {
    if (i >= j) {
        return;
    }

    int pivot = partition(A, i, j, i +  rand() % (j - i + 1));
    randomized_quicksort(A, i, pivot - 1);
    randomized_quicksort(A, pivot + 1, j);
}

int main() {
     vector<int> A = {5, 4, 2, 1, 7, 6, 3, 8, 9};
    
    // Using quicksort
    quicksort(A, 0, A.size() - 1);
    for (int num : A) {
         cout << num << " ";
    }
     cout <<  endl;

    // Reset the array
    A = {5, 4, 2, 1, 7, 6, 3, 8, 9};

    // Using randomized quicksort
    randomized_quicksort(A, 0, A.size() - 1);
    for (int num : A) {
         cout << num << " ";
    }
     cout <<  endl;

    return 0;
}
