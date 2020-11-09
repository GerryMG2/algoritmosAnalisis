
#include <iostream>
#include <stdexcept>


using namespace std; 

template <class Q>
void swap(Q* a, Q * b)  
{  
    Q t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
template <class Q>
int partition (Q arr[], int low, int high)  
{  
    Q pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j].key < pivot.key)  
        {  
            i++; // increment index of smaller element  
            swap<Q>(&arr[i], &arr[j]);  
        }  
    }  
    swap<Q>(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
template <class Q>
void quickSort(Q arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition<Q>(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort<Q>(arr, low, pi - 1);  
        quickSort<Q>(arr, pi + 1, high);  
    }  
}  


//quickSort<structura>(arr,0,size -1);